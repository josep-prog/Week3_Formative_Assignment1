import random
import time

import fastsum

numbers = [random.randint(1, 100) for _ in range(5000000)]


def python_sum(lst):
    total = 0
    for n in lst:
        total += n
    return total


start = time.perf_counter()
python_sum(numbers)
python_time = time.perf_counter() - start

start = time.perf_counter()
fastsum.fast_sum(numbers)
c_time = time.perf_counter() - start

print("Python:", python_time)
print("C Extension:", c_time)
print("Speedup:", python_time / c_time)
