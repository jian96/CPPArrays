#include <cstdio>
#include <chrono>
// this is not working properly, times are too same
using namespace std::chrono;

template <typename F>
void measure_time(const char* desc, F foo)
{  //bool* showTimeScale) {
    auto start = system_clock::now();
    foo();
    auto stop = system_clock::now();
    auto elapsed_ns = duration_cast<nanoseconds>(stop - start).count();
    auto elapsed_us = duration_cast<microseconds>(stop - start).count();
    printf("%s: %lld microseconds, %lld nanoseconds\n", desc, elapsed_us, elapsed_ns);
}

int main() {
    const int n = 1000;
    int arr[n];
    measure_time("Multiply each element", [&]() {
        for (int i = 0; i < n; i++)
            arr[i] *= i;
    });

    const int m = 1000;
    int arr_sec[m];
    measure_time("Access same element", [&]() {
        for (int j = 0; j < m; j++)
            arr_sec[0] *= j;
    });
}