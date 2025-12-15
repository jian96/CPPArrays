// from https://www.cs.uaf.edu/2009/spring/cs641/lecture/02_12_cache.html?utm_source=chatgpt.com
#include <cstdio>
#include <chrono>
// the above article is from 2009 and therefore a bit outdated on what modern CPUs are capable of,
// but the general idea of cache lines and spatial locality still holds true in 2024.
// however, this specific example shows the opposite results because modern CPUs have become much better at prefetching data
// and optimizing memory access patterns.
// in this specific example with n = 200000, accessing different elements in an array can be faster than repeatedly accessing the same element
// this is probably cuz in the second case, arr_sec[0] remains in the cache so further access is a lot faster. whereas in the first case, accessing different elements may lead to cache misses if the array is large enough
// thus, the results can vary based on the CPU architecture, cache size, and other factors

// i'm trying to do it with n = bigger number but stackoverflow so I will implement a heap version in another branch
using namespace std::chrono;

void print_array(int arr[], int size)
{
	for (int i = 0; i < size; i++)
	{
		printf("%d ", arr[i]);
	}
	printf("\n");
}

int main()
{
	volatile int sum = 0;
	printf("--- accessing diff elements in parallel\n");
	const int n = 200000;
	int arr[n];
	int i;

	time_point<system_clock> start = system_clock::now();
	for (i = 0; i < n; i++)
		sum += arr[i];
	time_point<system_clock> stop = system_clock::now();

	time_t elapsed_us = duration_cast<microseconds>(stop - start).count();
	printf("time elapsed: %lld microseconds\n", elapsed_us);
	print_array(arr, 10);
	// OTHER SECTION
	printf("--- accessing the same element\n");
	
	const int m = 200000;
	int arr_sec[m] = {0};
	int j;

	time_point<system_clock> start_2 = system_clock::now();
	for (j = 0; j < m; j++)
		sum += arr_sec[0];
	time_point<system_clock> stop_2 = system_clock::now();

	time_t elapsed_us_2 = duration_cast<microseconds>(stop_2 - start_2).count();
	printf("time elapsed: %lld microseconds\n", elapsed_us_2);
	print_array(arr_sec, 2);
}