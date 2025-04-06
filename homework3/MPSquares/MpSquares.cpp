#include <iostream>
#include <omp.h>

int main() {
    const int N = 100;
    long long sum = 0;

    // Parallel region with OpenMP
    #pragma omp parallel
    {
        long long local_sum = 0;

        // Each thread computes a portion of the sum
        #pragma omp for
        for (int i = 1; i <= N; ++i) {
            local_sum += i * i;
        }

        // Critical section to safely update the global sum
        #pragma omp critical
        {
            sum += local_sum;
        }
    }

    std::cout << "The sum of squares from 1 to " << N << " is: " << sum << std::endl;
    return 0;
}