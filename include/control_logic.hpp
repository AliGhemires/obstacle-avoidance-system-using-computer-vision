#ifndef CONTROL_LOGIC_HPP
#define CONTROL_LOGIC_HPP

#include <opencv2/opencv.hpp>
#include <vector>

class ControlLogic {
public:
    ControlLogic();
    // Sets the position of the detected obstacle
    void setObstaclePosition(const cv::Point& obstaclePos);
    // Calculates the next move for the robot based on obstacle position
    cv::Point calculateNextMove();
    // Checks if an obstacle is detected
    bool isObstacleDetected();

    // Update control logic with the distance of the nearest obstacle
    // Adding this method to provide external control of behavior based on distance
    void update(int obstacleDistance);

private:
    cv::Point obstaclePosition;
    bool obstacleDetected;
    
    // Additional members for improved logic handling
    int speed;             // Current speed of the robot
    int steeringAngle;     // Current steering angle of the robot
    
    // Constants for control logic
    static const int SAFE_DISTANCE = 50;        // Safe stopping distance in arbitrary units
    static const int WARNING_DISTANCE = 100;    // Distance where warnings are triggered
    static const int MAX_STEERING_ANGLE = 30;   // Maximum steering angle in degrees
    static const int REDUCED_SPEED = 10;        // Speed when an obstacle is nearby
    static const int NORMAL_SPEED = 20;         // Normal operational speed
};

#endif // CONTROL_LOGIC_HPP
