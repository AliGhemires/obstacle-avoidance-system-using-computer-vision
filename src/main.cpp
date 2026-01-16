#include <iostream>
#include <opencv2/opencv.hpp>
#include "obstacle_detector.hpp"
#include "control_logic.hpp"

// Main entry point for the Obstacle Avoidance System
int main(int argc, char** argv) {
    // Check command line arguments
    if (argc < 2) {
        std::cerr << "Usage: ./ObstacleAvoidanceSystem --run|--test|--data_path <path>" << std::endl;
        return 1;
    }

    // Initialize obstacle detector and control logic
    ObstacleDetector obstacleDetector;
    ControlLogic controlLogic;

    // Check for commands
    std::string command = argv[1];

    if (command == "--run") {
        // Real-time detection
        cv::VideoCapture cap(0); // Open the default camera
        if(!cap.isOpened()) {
            std::cerr << "Error: Could not open camera." << std::endl;
            return -1;
        }

        cv::Mat frame;
        while (true) {
            cap >> frame; // Capture frame
            if (frame.empty()) {
                std::cerr << "Error: Captured empty frame. Exiting." << std::endl;
                break;
            }

            // Process the frame for obstacle detection
            std::vector<cv::Point> obstacles = obstacleDetector.detectObstacles(frame);
            controlLogic.navigate(obstacles);

            // Display the frame with detected obstacles
            for (const auto& obstacle : obstacles) {
                cv::circle(frame, obstacle, 5, cv::Scalar(0, 255, 0), -1);
            }
            cv::imshow("Obstacle Detection", frame);

            // Break loop with 'q'
            if (cv::waitKey(30) == 'q') break;
        }
        cap.release();
        cv::destroyAllWindows();
    } 
    else if (command == "--test") {
        // Run tests
        if (!controlLogic.runTests()) {
            std::cerr << "Test suite failed." << std::endl;
            return 1;
        }
    } 
    else if (command == "--data_path") {
        if (argc < 3) {
            std::cerr << "Error: Data path is required." << std::endl;
            return 1;
        }

        // Edge case to ensure the data is readable
        std::string dataPath = argv[2];
        if (!obstacleDetector.loadData(dataPath)) {
            std::cerr << "Error: Failed to load data from the specified path: " << dataPath << std::endl;
            return 1;
        }
        controlLogic.processData();
    } 
    else {
        std::cerr << "Invalid command." << std::endl;
        return 1;
    }

    return 0;
}
