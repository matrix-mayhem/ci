
#include "perception.hpp"
#include <cstdlib>
#include <ctime>

std::vector<Detection> simulatePerceptionFrames(int total_frames) {
    std::vector<Detection> results;
    std::srand(static_cast<unsigned int>(std::time(nullptr)));

    for (int frame = 0; frame < total_frames; ++frame) {
        int object_id = std::rand() % 100;
        float distance = 1.0f + static_cast<float>(std::rand() % 100) / 10.0f;

        results.push_back({frame, object_id, distance});
    }

    return results;
}

