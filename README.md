# CodeTestLib
搜索解两种方法:
1. 广度搜索: 能找到最优解，使用队列循环
2. 深度搜索: 能快速找到一个可行解，使用栈递归

降低时间复杂度思考方法:
1. 两层循环，复杂度O(n*n)
2. 一个选择是O(n*ln(n))，一个循环改成取半(二分法查找是ln(n)), 二分法排序.
3. 另一个选择O(n)，滑动窗口
4. 最好选择是O(1), Hash
5. [C++面试题](https://zhuanlan.zhihu.com/p/629336564)

## [各种算法的时间复杂度](https://zh.wikipedia.org/wiki/%E6%8E%92%E5%BA%8F%E7%AE%97%E6%B3%95)
|   算法   |   最好     |   中等   |    最差   | 例子                                              |
| --------|:----------|:----------|:----------|--------------------------------------------------|
| 红黑树   |            |  ln      |          | 平衡二叉树, map, set, multimap, and multiset       |
| 哈希表   |    1       |          |     N    | hash_map, hash_set, hash_multimap, hash_multiset |
| 快速排序 |            | N*ln     |     N^2  |                                                  |
| 计数排序 |            |  n+k     |           | n个[0, k]之间的整数, 不是比较排序                  |
| 选择算法 |            |  N       |           | 第k个最小数字                                     |
|         |            |          |           |                                                  |
|         |            |          |           |                                                  |

## 各种算法的空间复杂度

## 排序
1. 比较排序（Comparison sort）: 快速排序, 堆排序, 归并排序, 插入排序, 选择排序, 冒泡排序
2. 非比较排序 (Alternative Sorting)：基数排序 (counting sort), 计数排序, 桶排序
3. 稳定的排序
4. 不稳定的排序
5. 不实用的排序

## [第n小排序](https://blog.csdn.net/qq_39526250/article/details/94599580)
1. 排序之后取[k-1]，O(nLogn)
2. 开数组[k], O(NK)
3. 使用大顶堆, O(K + (N-K)lgK)
4. 快速排序思想, O(N)

## VSCode
1. [Introductory Videos for C++](https://code.visualstudio.com/docs/cpp/introvideos-cpp)
2. [开发神器VSCode配置C/C++环境](https://mp.weixin.qq.com/s/H4WsUtequaO0vLuIBXLX7w)
3. cpp: The C and C++ preprocessor; gcc: The C compiler; g++: The C++ compile
4. MinGW：MinGW是“Minimalist GNU for Windows”的缩写，是一个Windows上的GNU开发环境。它提供了GNU编译器和其他工具，可以用来编译和链接C和C++代码，生成Windows下的可执行文件和动态链接库。MinGW不包含UNIX/Linux下的系统库，因此无法编译使用这些库的代码
5. MSYS：MSYS是“Minimal SYStem”的缩写，是一个轻量级的UNIX/Linux兼容环境。它提供了一组UNIX/Linux命令和工具，可以在Windows上使用。与MinGW不同，MSYS包含UNIX/Linux下的系统库，因此可以用来编译和链接使用这些库的代码

## [www.hackerrank.com](https://www.hackerrank.com/)

### C++

### 1 Week Preparation Kit

### 1 Month Preparation Kit
1. The Maximum Subarray
2. Lily's Homework
3. [图搜索算法：DFS、BFS、GBFS、Dijkstra、A*](https://zhuanlan.zhihu.com/p/346666812)
4. 图搜索算法总结: CastleOnTheGrid.cpp
### 3 Months Preparation Kit

## [leetcode.com  leetcode.cn](https://leetcode.com)

## [Stack Overflow Algorithm](https://devtut.github.io/algorithm/)

## [cnblogs算法系列文章](https://www.cnblogs.com/huansky/p/13488234.html)

## [数据结构与算法](https://www.runoob.com/data-structures/data-structures-tutorial.html)

## [数据结构和算法](https://zhuanlan.zhihu.com/p/37289934)

## [数据结构教程](https://www.dotcpp.com/course/ds-start/)