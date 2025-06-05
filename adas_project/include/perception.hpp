#ifndef PERCEPTION_HPP
#define PERCEPTION_HPP

#include <vector>
#include <utility>  // for std::pair

struct Detection {
    int frame;
    int object_id;
    float distance;
};

// Function to simulate perception frames
std::vector<Detection> simulatePerceptionFrames(int total_frames);

#endif

