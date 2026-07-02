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

First, build the C extension:

*python3 setup.py build*

Then run the benchmark:

*python3 benchmark.py*

## 

## **What to Expect**

When you run the benchmark, the program compares:

* Python loop performance  
* C extension performance

You will see output like:

* Python execution time  
* C extension execution time  
* Speedup ratio (how many times faster C is)

## 

## **How It Works Internally**

The Python version processes each number in a loop inside Python, which is slower because Python is interpreted.

The C extension processes the same list using compiled C code, which reduces overhead and improves speed. This is why it performs better.