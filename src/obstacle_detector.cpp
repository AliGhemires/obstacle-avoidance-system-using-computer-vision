#include "obstacle_detector.hpp"
#include <opencv2/opencv.hpp>
#include <vector>

ObstacleDetector::ObstacleDetector() {
    // Constructor initialization if required
}

std::vector<cv::Rect> ObstacleDetector::detectObstacles(const cv::Mat& frame) {
    std::vector<cv::Rect> obstacles;
    cv::Mat gray, edges;

    // Validate input frame for empty or invalid matrices
    if (frame.empty() || frame.channels() != 3) {
        std::cerr << "Invalid input frame. Skipping detection." << std::endl;
        return obstacles;  // Return empty if frame is invalid
    }

    // Convert to grayscale
    cv::cvtColor(frame, gray, cv::COLOR_BGR2GRAY);

    // Use Canny edge detection with error handling
    try {
        cv::Canny(gray, edges, 100, 200);
    } catch (const cv::Exception& e) {
        std::cerr << "Canny edge detection failed: " << e.what() << std::endl;
        return obstacles;
    }

    // Find contours
    std::vector<std::vector<cv::Point>> contours;
    cv::findContours(edges, contours, cv::RETR_TREE, cv::CHAIN_APPROX_SIMPLE);

    // Filter contours to get rectangular obstacles
    for (const auto& contour : contours) {
        cv::Rect boundingBox = cv::boundingRect(contour);
        if (isValidObstacle(boundingBox)) {
            obstacles.push_back(boundingBox);
        }
    }

    return obstacles;
}

bool ObstacleDetector::isValidObstacle(const cv::Rect& boundingBox) {
    // Define thresholds for valid obstacles
    const int minSize = 30;  // Minimum width and height of obstacles
    const int maxSize = 200;  // Maximum width and height of obstacles

    if (boundingBox.area() == 0) return false; // Eliminate zero-area contours

    return (boundingBox.width >= minSize && boundingBox.height >= minSize &&
            boundingBox.width <= maxSize && boundingBox.height <= maxSize);
}
