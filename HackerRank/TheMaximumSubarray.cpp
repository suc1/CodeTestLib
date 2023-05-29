/*
Kadane算法: 最大子数列问题
https://baike.baidu.com/item/%E6%9C%80%E5%A4%A7%E5%AD%90%E6%95%B0%E5%88%97%E9%97%AE%E9%A2%98
https://zh.wikipedia.org/wiki/%E6%9C%80%E5%A4%A7%E5%AD%90%E6%95%B0%E5%88%97%E9%97%AE%E9%A2%98

1. 遍历该数组， 在遍历过程中， 将遍历到的元素依次累加起来， 当累加结果小于或等于0时， 从下一个元素开始，重新开始累加。
2. 累加过程中， 要用一个变量(max_so_far)记录所获得过的最大值
3. 一次遍历之后， 变量 max_so_far 中存储的即为最大子片段的和值。
*/