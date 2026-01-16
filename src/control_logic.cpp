#include "control_logic.hpp"
#include "obstacle_detector.hpp"
#include <iostream>
#include <chrono>

ControlLogic::ControlLogic() : speed(0), steeringAngle(0) {}

void ControlLogic::update(int obstacleDistance) {
    if (obstacleDistance <= 0) {
        // Handle sanity check for non-positive distances
        std::cout << "Invalid distance detected! Ignoring sensor data." << std::endl;
        return;
    }
    
    if (obstacleDistance < SAFE_DISTANCE) {
        // If the obstacle is within a safe distance, stop or avoid it.
        speed = 0;
        steeringAngle = MAX_STEERING_ANGLE;
        std::cout << "Obstacle detected! Stopping and turning." << std::endl;
    } else if (obstacleDistance < WARNING_DISTANCE) {
        // If the obstacle is in warning distance, slow down and steer away.
        speed = REDUCED_SPEED;
        steeringAngle = STEERING_ANGLE;
        std::cout << "Warning! Reducing speed and steering." << std::endl;
    } else {
        // If no obstacles are detected within a critical range, move forward at normal speed.
        speed = NORMAL_SPEED;
        steeringAngle = 0;
        std::cout << "Path clear. Moving forward." << std::endl;
    }
    applyControlActions();
}

void ControlLogic::applyControlActions() {
    // Here we would send commands to the robot's actuators to control speed and steering.
    // In this simulation, we merely print the intended actions.
    if (speed < 0 || steeringAngle < -180 || steeringAngle > 180) {
        // Sanity check for speed and steering values
        std::cout << "Invalid control actions: Speed = " << speed 
                  << ", Steering Angle = " << steeringAngle << " Ignored." << std::endl;
        return;
    }

    std::cout << "Applying control actions: Speed = " << speed 
              << ", Steering Angle = " << steeringAngle << std::endl;
}

int ControlLogic::getSpeed() const {
    return speed;
}

int ControlLogic::getSteeringAngle() const {
    return steeringAngle;
}
