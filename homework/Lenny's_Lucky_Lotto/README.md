# Lenny's Lucky Lotto

## Description

Lenny likes to play the game of lotto. In the lotto game, he picks a list of N unique numbers in the range from 1 to M. If his list matches the list of numbers that are drawn, he wins the big prize.

Lenny has a scheme that he thinks is likely to be lucky. He likes to choose his list so that each number in it is at least twice as large as the one before it. So, for example, if N = 4 and M = 10, then the possible lucky lists Lenny could like are:

```
1 2 4 8
1 2 4 9
1 2 4 10
1 2 5 10
```

Thus Lenny has four lists from which to choose.

Your job, given N and M, is to determine from how many lucky lists Lenny can choose.

## Input

There will be multiple cases to consider from input. The first input will be a number C (0 < C <= 50) indicating how many cases with which you will deal. Following this number will be pairs of integers giving values for N and M, in that order. You are guaranteed that 1 <= N <= 10, 1 <= M <= 2000, and N <= M. Each N M pair will occur on a line of its own. N and M will be separated by a single space.

## Output

For each case display a line containing the case number (starting with 1 and increasing sequentially), the input values for N and M, and the number of lucky lists meeting Lenny’s requirements. The desired format is illustrated in the sample shown below.

## Sample Input

```
3
4 10
2 20
2 200
```

## Sample Output

```
Case 1: n = 4, m = 10, # lists = 4
Case 2: n = 2, m = 20, # lists = 100
Case 3: n = 2, m = 200, # lists = 10000
```
