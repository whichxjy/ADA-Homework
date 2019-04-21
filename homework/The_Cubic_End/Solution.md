# Solution

题目给出了一个有趣的现象：如果一个数字串，以1，3，7，9结尾，则会有一个数，它的三次方以这个数字串结尾，且长度不会超过这个数字串。现在给出一个数字串，找到一个数的三次方以这个数字串结尾。

在平时列竖式的时候会发现，在乘法运算里，结果中最后 n 位的取值只取决于两个乘数的最后 n 位取值。对于给定的数字串，可从低位向高位逐个遍历，把从当前位到最低位表示的数当成尾数。对于被遍历每一位，可从 0~9 进行枚举，如果已经确定的数的三次方的尾数与前面确定的尾数相同，则继续枚举直至得到最终结果。

本题的难点在于操作数可能很大，在进行乘法运算时可能会超过 unsigned long long 所能表示的范围。可在立方取模时运用数论乘法求模：

`a^3 % m = (((a * a) % m) * a) % m`

因为a < m,所以先进行a*a再求模。利用公式减小数值范围。

但在位数过大时，unsigned long long 还是会溢出。这时可以运用到数论中的[乘法求模](https://en.wikipedia.org/wiki/Multiplication_algorithm#Fast_multiplication_algorithms_for_large_inputs)，在乘法过程中不断求模。