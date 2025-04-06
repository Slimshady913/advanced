import kotlin.concurrent.thread

fun main() {
    var sum = 0L // 공유 자원
    val lock = Any() // Lock 객체
    val threads = mutableListOf<Thread>()
    val range = 1..100
    val numThreads = 4 // Number of threads
    val chunkSize = (range.last - range.first + 1) / numThreads

    for (i in 0 until numThreads) {
        val start = range.first + i * chunkSize
        val end = if (i == numThreads - 1) range.last else start + chunkSize - 1
        threads.add(thread {
            val localSum = (start..end).sumOf { it.toLong() * it }
            synchronized(lock) { // 크리티컬 섹션
                sum += localSum
            }
        })
    }

    threads.forEach { it.join() } // Wait for all threads to finish
    println("The sum of squares from ${range.first} to ${range.last} is: $sum")
}