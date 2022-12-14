#include <bits/stdc++.h>

template <class DT = std::chrono::milliseconds,
          class ClockT = std::chrono::steady_clock>
class Timer {
    using timep_t = typename ClockT::time_point;
    timep_t _start = ClockT::now(), _end = {};

    public:
        void tick() { 
            _end = timep_t{}; 
            _start = ClockT::now(); 
        }
        
        void tock() { _end = ClockT::now(); }
        
        template <class T = DT> 
        auto duration() const { 
            gsl_Expects(_end != timep_t{} && "toc before reporting"); 
            return std::chrono::duration_cast<T>(_end - _start); 
        }
};

int main(void) {
    unsigned int startTime, endTime;
    startTime = clock();
    for (int i = 0; i < 100000000000; i++) {}
    endTime = clock();
    double elapsedTime = (double(endTime - startTime) / CLOCKS_PER_SEC);
    std::cout << elapsedTime << std::endl;
    return EXIT_SUCCESS;
}