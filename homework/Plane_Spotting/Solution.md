# Solution

为了比较各个时间区间的大小，需要设置一个 Period 存储区间的信息。与此同时，为了方便比较，需要重载 < 运算符。由于函数中涉及浮点数的比较，需要注意浮点数的精度误差，此处用 abs 函数和 limits 的 epsilon 函数处理。

在每一轮测试中，先枚举所有可能的区间，并将合乎条件的区间放入优先级队列中（维护一种偏序关系），最后再对优先级队列进行 k 次取值操作即可。
