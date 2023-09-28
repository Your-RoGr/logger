#include "timer.h"

Timer::Timer() {
    start = std::chrono::high_resolution_clock::now();
}

Timer::~Timer() {
    std::chrono::duration<float> duration = std::chrono::high_resolution_clock::now() - start;
    std::cout << "Code execution time " << duration.count() << " s" << std::endl;
    system("pause");
}
