#include "control_logic.hpp"
#include "obstacle_detector.hpp"
#include <iostream>
#include <chrono>

ControlLogic::ControlLogic(ObstacleDetector &detector) : detector(detector) {}

void ControlLogic::processFrame(const cv::Mat &frame) {
    // Step 1: Validate the input frame for empty or invalid matrices
    if (frame.empty()) {
        std::cerr << "Received empty frame, skipping processing." << std::endl;
        return;
    }

    // Step 2: Perform obstacle detection using ObstacleDetector
    std::vector<Obstacle> obstacles = detector.detectObstacles(frame);
    
    // Step 3: Decide on control actions based on detected obstacles
    for (const auto &obstacle : obstacles) {
        if (isObstacleInPath(obstacle)) {
            executeAvoidanceManeuver(obstacle);
        }
    }
}

bool ControlLogic::isObstacleInPath(const Obstacle &obstacle) {
    // Check if the detected obstacle is in the robot's path
    // Include edge case for obstacle size and position further validation
    // Example: Consider the obstacle width in decision
    if (obstacle.position.x < safeDistance &&
        obstacle.boundingBox.width > minimumObstacleWidth) {
        return true;
    }
    return false;
}

void ControlLogic::executeAvoidanceManeuver(const Obstacle &obstacle) {
    // A simple obstacle avoidance logic: move backward or turn based on obstacle position
    // Consider edge scenarios such as obstacle size
    if (obstacle.position.x < criticalDistance && obstacle.boundingBox.area() > criticalMinimumArea) {
        // Example: Move backwards
        std::cout << "Critical obstacle detected! Moving backward!\n";
    } else {
        // Example: Turn
        std::cout << "Turning to avoid obstacle at position: " << obstacle.position.x << "\n";
    }
}
