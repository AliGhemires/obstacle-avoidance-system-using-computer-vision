#include "control_logic.hpp"
#include <gtest/gtest.h>

// Test class for ControlLogic
class ControlLogicTest : public ::testing::Test {
protected:
    ControlLogic control_logic;

    // Set up any common properties or states
    void SetUp() override {
        // Initialization code if needed
    }
};

// Test for obstacle avoidance logic
TEST_F(ControlLogicTest, AvoidObstacle_WhenObstacleDetected)
{
    control_logic.setObstacleDetected(true);
    EXPECT_TRUE(control_logic.shouldAvoidObstacle());
}

// Test for no obstacle case
TEST_F(ControlLogicTest, NoObstacle_WhenNoneDetected)
{
    control_logic.setObstacleDetected(false);
    EXPECT_FALSE(control_logic.shouldAvoidObstacle());
}

// Test response to obstacle detection
TEST_F(ControlLogicTest, ResponseToDetection)
{
    control_logic.setObstacleDetected(true);
    control_logic.updateControlState();
    EXPECT_EQ(control_logic.getCurrentState(), ControlState::AVOID);
}

// Test proper state when no obstacles are detected
TEST_F(ControlLogicTest, StateWhenClear)
{
    control_logic.setObstacleDetected(false);
    control_logic.updateControlState();
    EXPECT_EQ(control_logic.getCurrentState(), ControlState::GO);
}

// Test scenario with multiple detections over time
TEST_F(ControlLogicTest, MultipleDetections)
{
    control_logic.setObstacleDetected(true);
    control_logic.updateControlState();
    EXPECT_EQ(control_logic.getCurrentState(), ControlState::AVOID);
    control_logic.setObstacleDetected(false);
    control_logic.updateControlState();
    EXPECT_EQ(control_logic.getCurrentState(), ControlState::GO);
}

// Edge case: Rapid alternating detections
TEST_F(ControlLogicTest, RapidDetectionChanges)
{
    // Alternates between detection states quickly
    control_logic.setObstacleDetected(true);
    control_logic.updateControlState();
    EXPECT_EQ(control_logic.getCurrentState(), ControlState::AVOID);
    control_logic.setObstacleDetected(false);
    control_logic.updateControlState();
    EXPECT_EQ(control_logic.getCurrentState(), ControlState::GO);
    control_logic.setObstacleDetected(true);
    control_logic.updateControlState();
    EXPECT_EQ(control_logic.getCurrentState(), ControlState::AVOID);
}

// Edge case: Ensure system handles persistent obstacles correctly
TEST_F(ControlLogicTest, PersistentObstacle)
{
    // Simulate persistent obstacle presence
    control_logic.setObstacleDetected(true);
    control_logic.updateControlState();
    EXPECT_EQ(control_logic.getCurrentState(), ControlState::AVOID);
    control_logic.updateControlState();  // Repeat without change
    EXPECT_EQ(control_logic.getCurrentState(), ControlState::AVOID);
}

// Main function for running tests
int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
