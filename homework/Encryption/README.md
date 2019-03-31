# Encryption    

## Description

Alice is considering about sending some messages to Bob. However, she will feel embarrassed if the messages are read by others. Alice is so smart that she develops a novel encryption method. Alice will send two strings to Bob. We call them String_A and String_B. The meaningful message that Alice really want to send is hidden in String_A and String_B. We call the meaningful message String_M. String_M satisfies some rules as follows.


1) String_M is the maximum-length common subsequence of String_A and String_B;

2) A subsequence of a given sequence is the given sequence with some elements (possible none) left out.


Given String_A and String_B, Bob wants to know how long String_M is. However, Bob is not good at mathematics. Since you are the most NB (Nice-and-Brilliant) Hacker in campus, Bob ask you to help him. Given String_A and String_B, could you calculate the length of String_M ?
 
## Input

The input contains many test cases. Each test case contains two lines. The first line is the String_A. The second line is the String_B. (1<=length<=1000)
 

## Output

For each test case, you only need to output an integer in a line.
 
## Sample Input

```
abcdefghij
badfhcajie
```

## Sample Output

```
5
```
