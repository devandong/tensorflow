#include <chrono>

#ifndef TENSORFLOW_LITE_DELEGATES_GPU_METAL_SIMPLE_TIMER_H_
#define TENSORFLOW_LITE_DELEGATES_GPU_METAL_SIMPLE_TIMER_H_

class MetalTimer {
    using Tp = std::chrono::high_resolution_clock::time_point;
public:
    void Start() {
        if (started_) return;
        started_ = true;
        start_point_ = std::chrono::high_resolution_clock::now();
    }

    void Stop() {
        if (!started_) return;
        end_point_ = std::chrono::high_resolution_clock::now();
        started_ = false;
    }

    double GetTimeMS() {
        if (started_) return 0.f;
        double time_ms = std::chrono::duration_cast<std::chrono::microseconds>(
            end_point_ - start_point_).count();
        
        return time_ms / 1000.0;
    }
private:
    bool started_ = false;
    Tp start_point_;
    Tp end_point_;
};

#endif

