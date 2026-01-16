#ifndef OBSTACLE_DETECTOR_HPP
#define OBSTACLE_DETECTOR_HPP

#include <vector>
#include <opencv2/core.hpp>
#include <opencv2/imgproc.hpp>
#include <opencv2/highgui.hpp>

/**
 * @class ObstacleDetector
 * @brief A class for detecting obstacles in a given image frame.
 */
class ObstacleDetector {
public:
    /**
     * @brief Constructor initializes the obstacle detector.
     */
    ObstacleDetector();
    
    /**
     * @brief Destructor cleans up any used resources.
     */
    ~ObstacleDetector();

    /**
     * @brief Detects obstacles in the provided frame.
     * 
     * It processes the image to find and outline obstacles based on contours.
     * 
     * @param frame The input image frame in which to detect obstacles.
     * @return A vector of rectangles representing the bounding boxes of detected obstacles.
     */
    std::vector<cv::Rect> detectObstacles(const cv::Mat& frame);

    /**
     * @brief Sets the threshold for edge detection.
     *
     * This threshold is used by the Canny edge detection algorithm.
     * 
     * @param lowThreshold The lower threshold for the hysteresis procedure.
     * @param highThreshold The higher threshold for the hysteresis procedure.
     */
    void setThreshold(int lowThreshold, int highThreshold);

private:
    /**
     * @brief Low threshold value for edge detection.
     */
    int lowEdgeThreshold;

    /**
     * @brief High threshold value for edge detection.
     */
    int highEdgeThreshold;
};

#endif // OBSTACLE_DETECTOR_HPP
