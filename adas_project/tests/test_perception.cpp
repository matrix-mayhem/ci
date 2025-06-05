#include "gtest/gtest.h"
#include "../include/perception.hpp"

// Test that 10 frames are generated
TEST(PerceptionFrameTest, GeneratesCorrectFrameCount) {
    auto detections = simulatePerceptionFrames(10);
    EXPECT_EQ(detections.size(), 10);
}

// Test that frames are in correct order and IDs are in range
TEST(PerceptionFrameTest, FrameOrderAndRange) {
    auto detections = simulatePerceptionFrames(5);

    for (size_t i = 0; i < detections.size(); ++i) {
        EXPECT_EQ(detections[i].frame, i);
        EXPECT_GE(detections[i].object_id, 0);
        EXPECT_LT(detections[i].object_id, 100);
        EXPECT_GE(detections[i].distance, 1.0f);
        EXPECT_LE(detections[i].distance, 10.9f); // since rand() % 100 / 10.0f
    }
}

