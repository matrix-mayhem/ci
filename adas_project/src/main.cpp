//#include <opencv2/opencv.hpp>
#include "perception.hpp"
#include <dlt/dlt.h>
#include <iostream>
#include <thread>
#include <chrono>

DLT_DECLARE_CONTEXT(perceptionCtx);

int main() {
    DLT_REGISTER_APP("PERC", "Perception Binary");
    DLT_REGISTER_CONTEXT(perceptionCtx, "PER", "Perception Module");

    DLT_LOG(perceptionCtx, DLT_LOG_INFO, DLT_STRING("Perception application started."));
    std::cout << "Starting basic perception module...\n";

    auto detections = simulatePerceptionFrames(10);

    for (const auto& d : detections) {
        std::cout << "[Frame " << d.frame << "] Detected object ID: "
                  << d.object_id << ", Distance: " << d.distance << " meters\n";

        DLT_LOG(perceptionCtx, DLT_LOG_INFO,
                DLT_STRING("[Frame]"),
                DLT_INT(d.frame),
                DLT_STRING("Detected ID:"),
                DLT_INT(d.object_id),
                DLT_STRING("Dist:"),
                DLT_FLOAT32(d.distance));

        if (d.frame % 2 == 0) {
            DLT_LOG(perceptionCtx, DLT_LOG_VERBOSE, DLT_STRING("Intermediate processing..."));
        }

        std::this_thread::sleep_for(std::chrono::seconds(1));
    }

    DLT_LOG(perceptionCtx, DLT_LOG_INFO, DLT_STRING("Perception module finished."));
    DLT_UNREGISTER_CONTEXT(perceptionCtx);
    DLT_UNREGISTER_APP();

    return 0;
}

