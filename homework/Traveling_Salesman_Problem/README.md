# Traveling Salesman Problem

## Description

有编号1到N的N个城市，问从1号城市出发，遍历完所有的城市并最后停留在N号城市的最短路径长度。

## Input

第一行整数 T 表示有 T 组数据 （T<=20）

每个 case 读入一个N( 2 <= N <= 20)，接着输入 N 行，第 i 行有两个整数 xi 和 yi 表示第 i 个城市坐标轴上的坐标，两个城市的距离定义为欧氏距离。
 
## Output

每个case输出一个浮点数表示最短路径。四舍五入保留两位小数。

## Sample Input

```
1
4
0 0
1 0
0 1
1 1
```

## Sample Output

```
3.41
```