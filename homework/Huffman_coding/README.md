# Huffman coding

## Description

In computer science and information theory, a Huffman code is an optimal prefix code algorithm.

In this exercise, please use Huffman coding to encode a given data.

You should output the number of bits, denoted as B(T), to encode the data:

B(T) = ∑ f(c) * dT(c),

where f(c) is the frequency of character c, and dT(c) is be the depth of character c's leaf in the tree T.

## Input

The first line is the number of characters n.

The following n lines, each line gives the character c and its frequency f(c).

## Output

Output a single number B(T).

## Sample Input

```
5

0 5

1 4

2 6

3 2

4 3
```

## Sample Output

```
45
```

## Hint

0: 01

1: 00

2: 11

3: 100

4: 101
