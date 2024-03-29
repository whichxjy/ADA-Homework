# Substring

## 题目描述

一个字符串的子串表示原字符串中一段连续的部分。例如，字符串"121"的子串共有6个，它们分别是"1","2","1","12","21"和"121"。但是"11"不是子串，因为两个1不连续。我们认为空串也不是子串。

现有只包含'0'和'1'两种字符的子串，问它包含'0'和'1'数目相同的子串有多少。例如，字符串"0101"所包含的符合条件子串有四个，它们分别是"01","10","01","0101"。

## 输入格式

输入第一行为一个数 T <= 10，表示数据的组数。

接着T行，每行一个只包含"0"与"1"的字符串。字符串的长度不超过10000。

所有字符串长度加起来不超过 25000。

## 输出格式

输出为T行，T个数，表示符合条件的子串的个数

## 样例输入

```
2
00110011
0101
```

## 样例输出

```
10
4
```

## 提示

```
"01","10","01","0011","0110","1100","1001","0011","011001","00110011"共 10 个。
```