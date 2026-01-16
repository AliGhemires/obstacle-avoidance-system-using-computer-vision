#include "obstacle_detector.hpp"
#include <opencv2/opencv.hpp>
#include <iostream>
#include <vector>

// Constructor
ObstacleDetector::ObstacleDetector() {
    // Initialization code here.
}

// Method to process the image and detect obstacles
std::vector<cv::Rect> ObstacleDetector::detectObstacles(const cv::Mat& frame) {
    std::vector<cv::Rect> detectedObstacles;
    cv::Mat gray, edges;

    // Check if the input frame is empty
    if (frame.empty()) {
        std::cerr << "Error: Input frame is empty. \n";
        return detectedObstacles;  // Return an empty list.
    }

    // Convert the frame to grayscale
    cv::cvtColor(frame, gray, cv::COLOR_BGR2GRAY);

    // Detect edges using Canny Algorithm
    cv::Canny(gray, edges, 100, 200);

    // Find contours from the edges
    std::vector<std::vector<cv::Point>> contours;
    cv::findContours(edges, contours, cv::RETR_EXTERNAL, cv::CHAIN_APPROX_SIMPLE);

    // Filter out the rectangles from contours
    for (const auto& contour : contours) {
        cv::Rect boundingBox = cv::boundingRect(contour);
        
        // Add filtering logic based on bounding box properties
        if (boundingBox.area() > 500) { // Minimum area threshold
            if (boundingBox.width > 10 && boundingBox.height > 10) { // Minimum dimension threshold to reduce noise
                detectedObstacles.push_back(boundingBox);
            }
        }
    }

    return detectedObstacles;
}

// Method to visualize detected obstacles on a frame
void ObstacleDetector::drawObstacles(cv::Mat& frame, const std::vector<cv::Rect>& obstacles) {
    if (!frame.empty() && !obstacles.empty()) {
        for (const auto& obstacle : obstacles) {
            cv::rectangle(frame, obstacle, cv::Scalar(0, 255, 0), 2);
        }
    } else {
        std::cerr << "Warning: Empty frame or no obstacles to draw. \n";
    }
}

// Destructor
ObstacleDetector::~ObstacleDetector() {
    // Cleanup code here if needed.
}
