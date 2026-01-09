# Max Subarray Benchmark

This project benchmarks different algorithms for the **Maximum Subarray Problem**.

## Overview

- Compare **brute force** vs **divide-and-conquer (recursive)** algorithms.  
- Measure execution time on arrays of varying sizes using **high-resolution `clock_gettime()`**.  
- Batch runs implemented to get reliable average timings.

## Files

| File | Description |
|------|-------------|
| `Max_Subarray_Brute_Force.c` | Brute force implementation |
| `CLRS_Max_Subarray.c` | Divide-and-conquer / recursive implementation |
| `time.c` | Benchmarking / timing code using `clock_gettime()` |
| `benchmarking.h` | Header with function declarations |
| `.gitignore` | Ignore compiled outputs |

## Results / Insights

- Brute force is faster for very small arrays, recursive is faster for larger arrays.  
- Using high-resolution timing, we found that **recursion starts outperforming brute-force at array size ~17** on this machine.  
- Timing now produces meaningful results thanks to `clock_gettime()` and batching.

## How to Compile & Run

```bash
# Compile all source files
clang *.c -O2 -Wall -Wextra -std=c11 -o benchmark

# Run the benchmark
./benchmark
