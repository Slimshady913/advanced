import asyncio
import numpy as np
import time

async def file_read(): #동시 실행 가능 실행하는데 1초
    print("Reading file...")
    await asyncio.sleep(1) # 비동기 파일 I/O 시뮬레이션(cpu 사용 안함)
    print("File read complete.")
    return np.random.rand(1000)

async def process_data(data): # 동시 실행 가능X 실행하는데 5초
    print("Processing data...")
    time.sleep(1) # 동기적 데이터 처리 시뮬레이션(cpu 사용용)
    print("Data processing complete.")
    return np.mean(data)

async def main():
    tasks = []
    for i in range(5):
        tasks.append(file_read())
    file_contents = await asyncio.gather(*tasks)

    tasks = []
    for data in file_contents:
        tasks.append(process_data(data))
    processed_results = await asyncio.gather(*tasks)
    print("Processed results:", processed_results)

if __name__ == "__main__":
    asyncio.run(main())
