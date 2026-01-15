# Obstacle Avoidance System Using Computer Vision

## Project Overview

## Features
- **Real-time Obstacle Detection**: Integrated from a live camera feed to allow instant reaction to hazards.
- **Synthetic Data Generator**: Helps simulate various test scenarios to evaluate system behavior.
- **Deterministic Testing Algorithms**: Ensures that the system’s response is consistent and reliable.
- **Command Line Interface (CLI)**: For straightforward execution and testing of the system.
- **Logging Mechanisms**: Provides comprehensive insights into obstacle detection outcomes.
- **Detailed Performance Metrics**: Evaluates the system’s effectiveness and efficiency comprehensively.

## Installation and Running the Project
To start using the project, please follow these steps:

1. **Clone the Repository**:
 ```bash
 git clone <repository-url>
 cd ObstacleAvoidanceSystem
 ```

2. **Compile the Project using CMake**:
 
 Ensure you have all requisite tools and CMake installed, then execute:
 ```bash
 mkdir build && cd build
 cmake ..
 make
 ```

3. **Run the Main Application**:

 - **To execute tests**:
 ```bash
 ./ObstacleAvoidanceSystem --test
 ```

 - **To process synthetic data**:
 ```bash
 ./ObstacleAvoidanceSystem --data_path ./data/synthetic_data.csv
 ```

 - **To run the system in real-time**:
 ```bash
 ./ObstacleAvoidanceSystem --run
 ```

## Example Output
Here’s an example of what you might see when running the system:
```plaintext
INFO: Starting obstacle avoidance system...
INFO: Loading data from ./data/synthetic_data.csv...
INFO: Detected 4 obstacles in the path.
Obstacle 1: Distance: 1.2m, Angle: 30 degrees
Obstacle 2: Distance: 2.5m, Angle: -15 degrees
Obstacle 3: Distance: 0.8m, Angle: 10 degrees
Obstacle 4: Distance: 3.0m, Angle: 45 degrees
INFO: Navigating around detected obstacles...
INFO: Navigation complete. No collisions detected!
```

## Testing the Project
To verify the system’s functioning and reliability, execute:
```bash
./ObstacleAvoidanceSystem --test
```
This command runs all tests, ensuring the system achieves accurate obstacle detection and operates efficiently under varied conditions.

### Test Plan Highlights
- Validate obstacle detection accuracy within specified thresholds.
- Evaluate performance under diverse lighting conditions.
- Assess system response to sudden and irregularly shaped obstacles.

## Repo Layout
```
- CMakeLists.txt
- README.md
- data/synthetic_data.csv
- include/control_logic.hpp
- include/obstacle_detector.hpp
- src/control_logic.cpp
- src/main.cpp
- src/obstacle_detector.cpp
- tests/test_control_logic.cpp
- tests/test_obstacle_detector.cpp
```

## Conclusion
