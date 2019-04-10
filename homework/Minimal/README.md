# Minimal

## Description

There are two sets S1 and S2 subjecting to:

(1) S1, S2 are both the subsets of {x | x is an integer and 0 < x < 1,000,000}

(2) 0 < |S1 | < |S2| < 500

```
F(S1 ,S2) = min {|a1-b1| + |a2 – b2| + … + | aN –bN |}
in which ai ∈ S1, bi ∈ S2
         ai ≠ aj if i ≠ j
         bi ≠ bj if i ≠ j
(i, j = 1、2、… 、N，N = |S1|)
```

## Input

The first line contains an integer indicating the number of test cases.

For each test case, there are two integers N and M in the first line. N is the number of elements in S1 while M is the number of elements in S2. There are N+M lines that follow. In the first N lines are the integers in S1, while the last M lines S2. There is NO bland line between two cases.

## Output

For each test case, print the result of F(S1 ,S2), one case per line. There is NO bland line between two cases.

## Sample Input

```
1
2 3
30
20
50
10
40
```

## Sample Output

```
20
```