# Shortest Path 2

## Description

N cities named with numbers 1 ... N are connected with one-way roads. For each pair of cities i and j, you need to find the shortest path from city i to city j.

## Input

The first line contains three integers N, K and Q (2 <= N <= 100, 1 <= K <= 10000, 1 <= Q <= 10000). N is the number of cities, K is the number of roads, and Q is the number of queries. Each of following K lines contains three integers i, j, d (1 <= i,j <= N, 0 < d < 10000), indicates there is a road from city i to city j, and its length is d. The next Q lines describes the queries, each line contains two integers i and j (1 <= i, j <= N). 

## Output
For each query, you need to print the shortest path in one line. If there is no path between the query cities pair, you should print "-1". 

## Sample Input

```
4 3 2
1 2 3
2 3 4
2 4 3
1 3
2 4
```

## Sample Output

```
7
3
```
