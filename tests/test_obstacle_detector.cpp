#include <gtest/gtest.h>
#include "obstacle_detector.hpp"
#include <vector>

// Mock data for testing different obstacle detection scenarios
std::vector<std::vector<int>> mock_data_1 = {{0, 0, 0, 0}, {0, 1, 1, 0}, {0, 0, 0, 0}}; // Simple obstacle detection
std::vector<std::vector<int>> mock_data_2 = {{0, 0, 1, 0}, {0, 1, 1, 1}, {0, 0, 0, 0}}; // Complex obstacles
std::vector<std::vector<int>> mock_data_3 = {{1, 1, 1, 1}, {1, 1, 1, 1}, {1, 1, 1, 1}}; // Full blockage
std::vector<std::vector<int>> mock_data_4 = {{0, 0, 0, 0}, {0, 0, 0, 0}, {0, 0, 0, 0}}; // No obstacle

class ObstacleDetectorTest : public ::testing::Test {
protected:
    ObstacleDetector detector;

    // Helper function to convert mock data to image format
    cv::Mat createMockImage(const std::vector<std::vector<int>>& data) {
        cv::Mat img(data.size(), data[0].size(), CV_8UC1);
        for (size_t i = 0; i < data.size(); ++i) {
            for (size_t j = 0; j < data[i].size(); ++j) {
                img.at<uchar>(i, j) = data[i][j] * 255; // Object presence as white
            }
        }
        return img;
    }
};

TEST_F(ObstacleDetectorTest, DetectsObstacleInSimpleScenario) {
    cv::Mat image = createMockImage(mock_data_1);
    auto obstacles = detector.detect(image);
    EXPECT_EQ(obstacles.size(), 1); // Expect one obstacle detected
}

TEST_F(ObstacleDetectorTest, DetectsMultipleObstaclesInComplexScenario) {
    cv::Mat image = createMockImage(mock_data_2);
    auto obstacles = detector.detect(image);
    EXPECT_GT(obstacles.size(), 1); // Expect multiple obstacles
}

TEST_F(ObstacleDetectorTest, DetectsWhenFullBlocked) {
    cv::Mat image = createMockImage(mock_data_3);
    auto obstacles = detector.detect(image);
    ASSERT_EQ(obstacles.size(), 1); // Expect a single, large obstacle detected
}

TEST_F(ObstacleDetectorTest, HandlesEmptyImage) {
    cv::Mat empty_img = cv::Mat::zeros(3, 4, CV_8UC1);
    auto obstacles = detector.detect(empty_img);
    EXPECT_EQ(obstacles.size(), 0); // Expect no obstacles
}

// New Test for No Obstacle Scenario
TEST_F(ObstacleDetectorTest, DetectsNoObstacle) {
    cv::Mat image = createMockImage(mock_data_4);
    auto obstacles = detector.detect(image);
    EXPECT_EQ(obstacles.size(), 0); // Expect no obstacles detected
}

// New Test for Edge Case with Single Dot Obstacle
TEST_F(ObstacleDetectorTest, HandlesSingleDotObstacle) {
    std::vector<std::vector<int>> single_dot_data = {{0, 0, 0, 0}, {0, 0, 1, 0}, {0, 0, 0, 0}};
    cv::Mat image = createMockImage(single_dot_data);
    auto obstacles = detector.detect(image);
    EXPECT_EQ(obstacles.size(), 1); // Expect a single obstacle detected
}

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
