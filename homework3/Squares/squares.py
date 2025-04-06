import threading

def calculate_square(start, end, lock, total_sum):
    local_sum = 0
    # 주어진 범위의 숫자들의 제곱 합 계산
    for i in range(start, end + 1):
        local_sum += i * i
    # 크리티컬 섹션
    with lock:
        total_sum[0] += local_sum

def main():
    total_sum = [0]  # 리스트를 사용하여 참조를 통해 값 공유
    lock = threading.Lock()
    threads = []
    num_threads = 4
    start, end = 1, 100
    step = (end - start + 1) // num_threads

    # 스레드별 범위 정의 및 생성
    for i in range(num_threads):
        thread_start = start + i * step
        thread_end = start + (i + 1) * step - 1 if i < num_threads - 1 else end
        thread = threading.Thread(target=calculate_square, args=(thread_start, thread_end, lock, total_sum))
        threads.append(thread)
        thread.start()

    # 모든 스레드가 완료될 때까지 대기
    for thread in threads:
        thread.join()

    print(f"The sum of squares from {start} to {end} is: {total_sum[0]}")

if __name__ == "__main__":
    main()