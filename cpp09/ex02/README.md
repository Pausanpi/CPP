# PmergeMe

Canonical Ford–Johnson (merge-insertion) sorter benchmarking `std::vector` vs `std::deque`.

## Overview
The program reads a sequence of strictly positive integers from the command line, validates them, and sorts them using a custom implementation of the merge-insertion (Ford–Johnson style) algorithm. It performs the sort separately on a `std::vector<int>` and a `std::deque<int>` to compare timings, then prints:

1. The original (unsorted) sequence.
2. The sorted sequence.
3. Time taken by each container implementation.

## Algorithm (Ford–Johnson / Merge-Insertion)
Implemented steps:
1. Pairing: Form consecutive pairs and orient them so each pair stores (max,min).
2. Sort maxima: Stable sort the pairs by their max value; these maxima form the initial sorted chain.
3. Seed insertion: Insert the first pair's min at the front of the chain.
4. Jacobsthal order: Generate the Ford–Johnson insertion order (derived from the Jacobsthal sequence) for the remaining mins.
5. Bounded binary insertion: For each pending min of pair i, binary search only within the prefix up to (and excluding) its own max position (classic optimization that reduces comparisons).
6. Leftover: If the original input length was odd, insert the leftover element at the end using lower_bound.
7. Result: Chain is fully sorted; the same procedure is applied to `std::deque` via a vector intermediary (comparison counts are equivalent; timing difference is due only to container mechanics).

Complexity: O(n log n) comparisons; element moves depend on container characteristics (vector shift vs deque segmented storage). This adheres closely to the canonical Ford–Johnson scheme for a single non-recursive pass (the classic recursive explanation collapses here because we sort the maxima directly via `stable_sort`).

## Input Validation
- Each argument must be a string of digits (0-9) representing a non-negative integer (zero allowed).
- Values must fit in signed 32-bit int (<= INT_MAX).
- On any invalid argument the program prints `Error` and exits with status 1.

## Build
From inside `cpp09/ex02`:

```sh
make        # builds the PmergeMe executable
make re     # rebuilds from scratch
make clean  # removes object files
make fclean # removes objects + executable
```

## Usage
```sh
./PmergeMe 3 5 9 7 4
```
Sample output:
```
Before: 3 5 9 7 4 
After:  3 4 5 7 9 
Time to process a range of 5 elements with std::vector : 13 us
Time to process a range of 5 elements with std::deque  : 14 us
```
Spaces after numbers are intentional (stream formatting).

Large test (Linux):
```sh
./PmergeMe $(shuf -i 1-100000 -n 3000 | tr '\n' ' ')
```
macOS alternative:
```sh
./PmergeMe $(jot -r 3000 1 100000 | tr '\n' ' ')
```

## Error Examples
```sh
./PmergeMe -1 2      # -> Error (negative)
./PmergeMe foo 5     # -> Error (non-digit)
./PmergeMe 0 4 2 0   # -> OK (zeros allowed)
```

## Timing Notes
- Timing uses `clock()` and reports microseconds (us). For very small `n` times may appear as 0 due to timer resolution.
- Vector vs Deque performance differences are minor for this algorithm; insertion costs dominate for both.

## Files
- `main.cpp` : Entry point, parses input, drives sorting, displays results.
- `PmergeMe.hpp/.cpp` : Class definition & algorithm implementation for both containers.

## Possible Improvements
- Track and report actual comparison counts to empirically verify theoretical bounds.
- Provide a fallback to standard algorithms (e.g., `std::sort`) for verification/testing (guarded by a macro).
- Add unit tests that compare output with a reference `std::vector` sorted copy.
- Implement a pure deque path without copying (current reuse keeps code small but slightly biases timing).

## License
Educational project (42 school exercise). Use freely for learning.

---
Feel free to adapt or extend this README as the implementation evolves.
