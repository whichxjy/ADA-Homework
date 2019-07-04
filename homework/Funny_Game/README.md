# Funny Game

## Description

Two players, Singa and Suny, play, starting with two natural numbers. Singa, the first player, subtracts any positive multiple of the lesser of the two numbers from the greater of the two numbers, provided that the resulting number must be nonnegative. Then Suny, the second player, does the same with the two resulting numbers, then Singa, etc., alternately, until one player is able to subtract a multiple of the lesser number from the greater to reach 0, and thereby wins. For example, the players may start with (25,7): 

```
25 7
11 7
4 7
4 3
1 3
1 0
```
 
an Singa wins.

## Input

The input consists of a number of lines. Each line contains two positive integers (<2^31) giving the starting two numbers of the game. Singa always starts first. The input ends with two zeros.

## Output

For each line of input, output one line saying either Singa wins or Suny wins assuming that both of them play perfectly. The last line of input contains two zeroes and should not be processed.

## Sample Input

```
28 15
15 24
0 0
```

## Sample Output

```
Singa wins
Suny wins
```