# Solution

这几题的解决方法差不多，主要差别在于数据量。

可将每个状态当成一个节点，从一种状态转移到另一种状态就是图上的一条边，于是就可以转化成搜索问题。这里用的是 BFS，在搜索过程中需要标记已经访问过的节点，以免重复访问。