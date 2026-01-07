# Max Subarray Benchmark

This project benchmarks different algorithms for the **Maximum Subarray Problem**.

## Overview

- Compare **brute force** vs **divide-and-conquer (recursive)** algorithms.  
- Measure execution time on arrays of varying sizes.  
- **Doesn't produce expected output.**
## Files

| File | Description |
|------|-------------|
| `Max_Subarray_Brute_Force.c` | Brute force implementation |
| `CLRS_Max_Subarray.c` | Divide-and-conquer / recursive implementation |
| `time.c` | Benchmarking / timing code |
| `benchmarking.h` | Header with function declarations |
| `.gitignore` | Ignore compiled outputs |


## Results / Insights

- Brute force is faster for very small arrays, recursive is faster for larger arrays.  
- Current timing does not give concrete output due to poor resolution of `clock()`; will fix in future updates.
