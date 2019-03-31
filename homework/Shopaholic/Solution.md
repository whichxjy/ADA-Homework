# Solution

可用贪心思想解决这个问题。每次都从商品中抽出三个最贵的，获得当前所得到的最大折扣，再从剩余的商品中继续抽取。为了在程序中实现这种思想，可按照价格从大到小将商品排序（此处用表示大于运算符的函数对象类 greater 来替换 sort 算法中的默认运算符）。最后取出第3、6、9、...、3n 个商品并将它们的价格相加即为最大折扣。