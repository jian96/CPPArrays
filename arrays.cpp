// from https://www.cs.uaf.edu/2009/spring/cs641/lecture/02_12_cache.html?utm_source=chatgpt.com
#include <cstdio>
#include <chrono>

using namespace std::chrono;

int main()
{
	time_point<system_clock> start = system_clock::now();
	///printf("fuck you");

	const int n = 1000;
	int arr[n];
	int i;
	for (i = 0; i < n; i++)
		arr[i] *= i;
	time_point<system_clock> stop = system_clock::now();
	time_t elapsed_ns = duration_cast<nanoseconds>(stop - start).count();
	time_t elapsed_us = duration_cast<microseconds>(stop - start).count();
	printf("time elapsed: %lld microseconds, %lld nanoseconds\n", elapsed_us, elapsed_ns);

	const int m = 1000;
	int arr_sec[m];
	int j;
	for (j = 0; j < m; j++)
		arr_sec[0] *= j;
	time_point<system_clock> start_2 = system_clock::now();
	printf("--- accessing the same element %d times\n", m);

	time_point<system_clock> stop_2 = system_clock::now();
	time_t elapsed_ns_2 = duration_cast<nanoseconds>(stop_2 - start_2).count();
	time_t elapsed_us_2 = duration_cast<microseconds>(stop_2 - start_2).count();
	printf("time elapsed: %lld microseconds, %lld nanoseconds", elapsed_us_2, elapsed_ns_2);
}