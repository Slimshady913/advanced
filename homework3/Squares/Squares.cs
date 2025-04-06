using System;
using System.Threading;

class Squares
{
    private static int sum = 0;
    private static readonly object lockObject = new object();

    static void Main(string[] args)
    {
        int start = 1;
        int end = 100;
        int threadCount = 4; // Number of threads to use
        int range = (end - start + 1) / threadCount;

        Thread[] threads = new Thread[threadCount];

        for (int i = 0; i < threadCount; i++)
        {
            int threadStart = start + i * range;
            int threadEnd = (i == threadCount - 1) ? end : threadStart + range - 1;

            threads[i] = new Thread(() => CalculateSquares(threadStart, threadEnd));
            threads[i].Start();
        }

        foreach (Thread thread in threads)
        {
            thread.Join();
        }

        Console.WriteLine($"The sum of squares from {start} to {end} is: {sum}");
    }

    private static void CalculateSquares(int start, int end)
    {
        int localSum = 0;
        for (int i = start; i <= end; i++)
        {
            localSum += i * i;
        }

        lock (lockObject)
        {
            sum += localSum;
        }
    }
}