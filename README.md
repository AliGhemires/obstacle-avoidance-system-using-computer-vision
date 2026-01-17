# Obstacle Avoidance System Using Computer Vision

## Tagline

## Project Overview

## Key Concepts
- **Computer Vision**: Techniques to process and analyze images from cameras to detect obstacles.
- **Modular C++ Architecture**: Designed for maintainability and scalability.

## Features
- Real-time obstacle detection from a camera feed.
- Synthetic data generator for testing purposes.
- Deterministic testing mechanisms for system checks.
- CLI-based interaction for running and testing the system.
- Comprehensive logging for obstacle detection outcomes.
- Metrics output for detailed performance evaluation.

## Installation and Running
To install and run the project, follow these steps:

1. **Clone the repository**:
```bash
git clone https://github.com/yourusername/obstacle-avoidance-system.git
cd obstacle-avoidance-system
```

2. **Build the project** using CMake:
```bash
mkdir build
cd build
cmake ..
make
```

3. **Run the application**:
- To test the system:
```bash
./ObstacleAvoidanceSystem --test
```
- To run with synthetic data:
```bash
./ObstacleAvoidanceSystem --data_path ./data/synthetic_data.csv
```
- To execute the main obstacle avoidance functionality:
```bash
./ObstacleAvoidanceSystem --run
```

## Example Output
Upon running the system with synthetic data, the output may look like the following:
```
Obstacle Avoidance System
-------------------------
Detecting obstacles...

Detected Obstacles:
1. Object at (x: 45, y: 20) - Distance: 2.5m
2. Object at (x: 30, y: 50) - Distance: 1.8m

Decision:
- Slow down
- Navigate around obstacle

Processing Time: 58ms
```

## Testing
To run the test suite, ensure you are in the build directory and execute:
```bash
make test
```
This will invoke the tests defined in `tests/test_obstacle_detector.cpp` and `tests/test_control_logic.cpp`, validating the system's accuracy and reliability.

### Edge Cases Considered
- **Varying Lighting Conditions**: Ensures robust detection across different lighting scenarios.
- **Sudden Obstacle Appearance**: Tests system reaction time and decision-making.
- **Multiple and Atypical Shapes**: Validates handling of complex scenes with diverse obstacle configurations.

## Project Layout
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
