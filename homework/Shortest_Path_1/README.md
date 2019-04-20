# Shortest Path 1

## Description

N cities named with number 1 ... N are connected with one-way roads. There are two kind of road. You need to pay for the normal roads when you go through them, but for the special road, you can earn some money instead. You live in city 1 and your girl friend lives in city N, if you want to visit her, you need to calculate how much you need to pay. 

## Input

The first line contains two integers N and K(2 <= N <= 100, 1 <= K <= 4000). N is the number of cities, K is the number of roads. Each of following K lines contains three integers i, j, d (1 <= i, j <= N), indicates there is a road from city i to city j. d >= 0 means this road is a normal road and costs d yuan, otherwise it means this road is a special road and you can earn -d yuan.

## Output

If you need to spend money, print the money you need to pay in one line; if you don't need to spend money you should print "0"; and if you can't reach city N, you should print "-1".

## Sample Input

```
3 3
1 2 3
2 3 2
1 3 6
```

## Sample Output

```
5
```
