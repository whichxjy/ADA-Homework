# Solution

暴力解法：两重循环，对于每一个 IP 地址，看看前面是否出现过，如果出现过，那么可以确定，先出现的 BBS ID 为 Main ID，后出现的为 MJ ID （马甲）。程序的时间复杂度为 O(n * m * L)，L 为字符串的最大长度。

其实本题可利用 STL 中的关联容器 map 来解决。先设置一个 map 表示从 IP 地址到 Main ID 的映射关系，再设置一个 vector 存储结果。每遇到一个 BBS ID 和一个 IP 地址时，先检查 map 中是否有该 IP 地址对应的 Main ID，如果有，则表示该 BBS ID 是马甲，需要将马甲与其对应的 Main ID 存储到结果中；否则表示该 BBS ID 是 Main ID，需要将 IP 地址和 Main ID 的映射存入 map 中。

题目中要求输出结果需要按照 Main ID 的字典序排列，因此应在输出结果前将 result 排序，此处可用 STL 中的 sort 函数来处理。为了正确地排序，还需要再编写一个比较函数 comp 来比较每个节点的 Main ID。

程序的时间复杂度变为 O(n * log(n) * L)，L 为字符串的最大长度。