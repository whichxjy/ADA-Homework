# The Cubic End

## Description

Given any string of decimal digits, ending in 1, 3, 7 or 9, there is always a decimal number, which when cubed has a decimal expansion ending in the original given digit string. The number need never have more digits than the given digit string.

Write a program, which takes as input a string of decimal digits ending in 1, 3, 7 or 9 and finds a number of at most the same number of digits, which when cubed, ends in the given digit string.

## Input

The input begins with a line containing only the count of problem instances, nProb, as a decimal integer, 1<=nProb<=1000 . This is followed by nProb lines, each of which contains a string of between 1 and 10 decimal digits ending in 1, 3, 7 or 9. 

## Output

For each problem instance, there should be one line of output consisting of the number, which when cubed, ends in the given digit string. The number should be output as a decimal integer with no leading spaces and no leading zeroes.

## Sample Input

```
4
123
1234567
435621
9876543213
```

## Sample Output

```
947
2835223
786941
2916344917
```