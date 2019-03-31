# LIS

## Description

A numeric sequence of ai is ordered if a1 <= a2 <= ... <= aN. Let the subsequence of the given numeric sequence (a1, a2, ..., aN) be any sequence (ai1, ai2, ..., aiK), where 1 <= i1 < i2 < ... < iK <= N. For example, the sequence (1, 7, 3, 5, 9, 4, 8) has ordered subsequences, e. g., (1, 7), (3, 4, 8) and many others. All the longest ordered subsequences are of length 4, e. g., (1, 3, 5, 8).
 
Your program, when given the numeric sequence, must find the length of its longest ordered subsequence L with the minimum aL.

## Input

The first line of input file contains the length of sequence N. The second line contains the elements of sequence - N integers in the range from 0 to 10^9 each, separated by spaces. (1 <= N <= 5000)


## Output

Output must contain two integers - the length of the longest ordered subsequence of the given sequence L and the minimum aL.


## Sample Input

```
7
1 7 3 5 9 4 8
```

## Sample Output

```
4 8
```