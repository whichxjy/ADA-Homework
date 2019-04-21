# Prime Gap

## Description

The sequence of n ? 1 consecutive composite numbers (positive integers that are not prime and not equal to 1) lying between two successive prime numbers p and p + n is called a prime gap of length n. For example, 24, 25, 26, 27, 28 between 23 and 29 is a prime gap of length 6.

Your mission is to write a program to calculate, for a given positive integer k, the length of the prime gap that contains k. For convenience, the length is considered 0 in case no prime gap contains k.

## Input

The input is a sequence of lines each of which contains a single positive integer. Each positive integer is greater than 1 and less than or equal to the 100000th prime number, which is 1299709. The end of the input is indicated by a line containing a single zero.

## Output

The output should be composed of lines each of which contains a single non-negative integer. It is the length of the prime gap that contains the corresponding positive integer in the input if it is a composite number, or 0 otherwise. No other characters should occur in the output.

## Sample Input

```
10
11
27
2
492170
0
```

## Sample Output

```
4
0
6
0
114
```
