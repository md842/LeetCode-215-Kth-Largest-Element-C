# LeetCode #215: Kth Largest Element in an Array (Daily Challenge 08/14/2023)
This repository contains a C solution to the LeetCode daily challenge #215 for 08/14/2023. https://leetcode.com/problems/kth-largest-element-in-an-array/

This solution beats 73.08% of users in runtime (94 ms) and 89.74% of users in memory usage (11.28 MB).

## Running
Navigate to the directory containing the extracted implementation, then simply run `make` with the included Makefile.
```
cd LeetCode-215-Kth-Largest-Element-C
make
```

The exact commands run by `make` are as follows:

```
cc -std=gnu17 -Wall -O0 -pipe -fno-plt -fPIC -c kth_largest.c -o kth_largest.o
cc -std=gnu17 -Wall -O0 -pipe -fno-plt -fPIC kth_largest.o -o kth_largest
```

There are no arguments; the test cases are hard-coded into the C file.

## Cleaning up
Navigate to the directory containing the extracted implementation, then simply run `make clean` with the included Makefile.

```
cd LeetCode-215-Kth-Largest-Element-C
make clean
```

The exact commands run by make clean are as follows:

```
rm -f kth_largest
rm -f kth_largest.o
```