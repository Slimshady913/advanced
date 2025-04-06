#include <iostream>
#include <thread>
#include <vector>
#include <mutex>

const int START = 1;
const int END = 100;

std::mutex mtx; // Mutex for critical section
long long sumOfSquares = 0; // Shared resource

void calculateSquareSum(int start, int end) {
    long long localSum = 0;
    for (int i = start; i <= end; ++i) {
        localSum += i * i;
    }

    // Critical section to update the shared resource
    std::lock_guard<std::mutex> lock(mtx);
    sumOfSquares += localSum;
}

int main() {
    const int numThreads = 4; // Number of threads
    std::vector<std::thread> threads;
    int range = (END - START + 1) / numThreads;

    for (int i = 0; i < numThreads; ++i) {
        int threadStart = START + i * range;
        int threadEnd = (i == numThreads - 1) ? END : threadStart + range - 1;
        threads.emplace_back(calculateSquareSum, threadStart, threadEnd);
    }

    for (auto& t : threads) {
        t.join();
    }

    std::cout << "Sum of squares from " << START << " to " << END << " is: " << sumOfSquares << std::endl;
    return 0;
}