# **Project 3: Building a Python Performance Extension**

In this project, I worked on improving the performance of a slow Python program that performs large numeric computations. The idea was to compare a normal Python solution with a faster C extension using the CPython API. This helped me understand how Python and C can work together to improve performance.

## **Why This Approach**

I used  Python first because it is easy to write and understand. However, it is slower when dealing with large data.

I then used a C extension because C runs much closer to the system level. It allows direct memory and loop handling, which makes heavy computations faster compared to Python loops.

## **How solution is Implemented**

I created a Python program that generates a large list of random numbers and calculates their sum.

Then I built a C extension called fastsum using the CPython API. Inside the extension, I loop through the Python list and compute the sum using C-level operations.

I registered the function so that Python can import it like a normal module.

## **How to Run the Project**

First, build the C extension in place so Python can import it directly from this folder:

*python3 setup.py build_ext --inplace*

Then run the benchmark:

*python3 benchmark.py*

<img width="1919" height="1079" alt="run_terminal" src="https://github.com/user-attachments/assets/9180295e-127c-4064-b5a2-a129f496baba" />


Note: plain \`python3 setup.py build\` also compiles the extension, but it places the \`.so\` file inside \`build/lib.../\` instead of the project folder, so \`import fastsum\` fails with \`ModuleNotFoundError\`. Using \`build_ext --inplace\` copies the compiled module into the current directory so the benchmark script can find it.

## 

## **What to Expect**

When you run the benchmark, the program compares:

* Python loop performance  
* C extension performance

You will see output like:

* Python execution time  
* C extension execution time  
* Speedup ratio (how many times faster C is)

## **Benchmark Results**

Actual results from running \`python3 benchmark.py\` on a list of 5,000,000 random integers:

| Version | Time (seconds) |
| :---- | :---- |
| Python | 0.1543 |
| C Extension | 0.0251 |
| **Speedup** | **6.1x** |

The C extension computed the same sum roughly 6 times faster than the pure Python loop.

## 

## **How It Works Internally**

The Python version processes each number in a loop inside Python, which is slower because Python is interpreted.

The C extension processes the same list using compiled C code, which reduces overhead and improves speed. This is why it performs better.
