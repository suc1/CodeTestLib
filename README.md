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
1. [C++11线程](https://mp.weixin.qq.com/s/rPjRTOTYK2SGr6WxgWI_Vg)
2. std::mutex, std::recursive_mutex, std::timed_mutex, std::recursive_timed_mutex
3. `std::lock_guard`是一个轻量级的互斥锁封装, `std::unique_lock`提供了更多的控制选项
4. `std::call_once`保证函数在多线程环境下只调用一次，可用于实现单例
5. `std::atomic`和`volatile`区别
6. `std::condition_variable`, `std::unique_lock`
7. std::future
    7.1 std::future比std::thread高级些，std::future作为异步结果的传输通道，通过get()可以很方便的获取线程函数的返回值
    7.2 `std::future`提供一种机制，使得在一个线程中启动一个任务，在另一个线程中等待这个任务完成，并且能够获取到任务的结果。你可以选择不等待，继续执行其他任务，或者使用 std::future::wait_for 或 std::future::wait_until 来在一段时间后检查任务的状态。
    7.3 `std::promise`提供一种机制，使得一个线程能够设置一个值或异常，并允许另一个线程在需要时获取这个值或异常
    7.4 std::promise用来包装一个值，将数据和future绑定起来
    7.5 std::packaged_task则用来包装一个调用对象，将函数和future绑定起来，方便异步调用
    7.6 `async`是比`future`，`packaged_task`，`promise`更高级的东西, 优先使用async
8. [thread、async、promise、future、packaged_task、function](https://www.zhihu.com/question/547132461/answer/2657296340)

### 1 Week Preparation Kit

### 1 Month Preparation Kit
1. The Maximum Subarray
2. Lily's Homework
3. [图搜索算法：DFS、BFS、GBFS、Dijkstra、A*](https://zhuanlan.zhihu.com/p/346666812)
4. 图搜索算法总结: CastleOnTheGrid.cpp
### 3 Months Preparation Kit

## 动态规划（Dynamic Programming）
1. wikipedia: 把原问题分解为相对简单的子问题
2. 适用于有重叠子问题 和 最优子结构性质(局部最优解能决定全局最优解)(大问题的最优解可以由小问题的最优解推出)
3. 一旦某个给定子问题的解已经算出，则将其记忆化存储，下次直接查表
4. 无后效性: 即子问题的解一旦确定，就不再改变. 未来与过去无关. 现在决定未来，未来与过去无关
5. 子问题重叠性质
6. 实例: 切割钢条问题、Floyd最短路问题、最大不下降子序列、矩阵链乘、凸多边形三角剖分、背包问题、最长公共子序列、最优二分搜索树
7. 背包问题( 整数背包问题 & 分数背包问题 ): 动态规划, 最优解-搜索法, 近似解-贪心法
 7.1 递推公式:A(Y)在下列取最大值: A(Y-1), 把最后添加物品拿来: P(j) + A( Y-w(j) )
 7.2 特例0 1背包问题
8. 最长公共子序列LCS: 不必是连续的位置, 广泛地应用在版本控制
 8.1 最长公共子串区别: 连续的位置
 8.2 几个序列就是几维空间. 两个序列就是平面: 到达[i][j]有三条路: [i-1][j-1], [i-1][j], [i][j-1]，取最大值
 8.2 两个序列的递推公式: f[i][j] = max{  f[i-1][j-1]+same(i,j), f[i-1][j], f[i][j-1] } 
 8.3 程序: 先初始化最外的行列 f[0][j] f[i][0]
 8.4 从左上角开始扩充（行列两层循环），利用递推公式，算出右下角
9. [DP意义](https://www.zhihu.com/question/23995189)
10. 凑钱: 贪心是鼠目寸光
11. 凑钱: f(n) = 1 + min{ f(n-1), f(n-5), f(n-11)}
12. 一个问题能否使用DP解决: 能将大问题拆成几个小问题，且满足无后效性、最优子结构性质
13. DAG最短路
14. DP自带剪枝, 只考虑可能成为最优解, 尽量缩小可能解空间
15. 如何设计: 1设计状态, 2状态转移方程(从哪里来, 到哪里去)
16. 最长上升子序列: Longest Increasing Subsequence
17. “按顺序递推”和“记忆化搜索”是实现DP的两种方式
18. [乌龟棋](https://www.luogu.com.cn/problem/P1541)
19. [01背包-采药 ](https://www.luogu.com.cn/problem/P1048)

20. [算法-动态规划 DP](https://blog.csdn.net/u013309870/article/details/75193592)
21. 自顶向下-思考的方法， 自底向上-求解的步骤， 递推公式是联系前后的桥梁
22. 递归实质是自顶向下, 有可能重复计算。也可以使用备忘录，但是写法麻烦
23. 循环实质是自底向上, 容易记忆查找
24. 动态规划的核心，先计算子问题，再由子问题计算父问题. 所以最好使用循环-自底向上
25. 钢条切割: 



2. [动态规划40题](https://zhuanlan.zhihu.com/p/91582909)

## [leetcode.com  leetcode.cn](https://leetcode.com)
1. [高效刷leetcode](https://www.zhihu.com/question/347453387/answer/2822291207)
## [Stack Overflow Algorithm](https://devtut.github.io/algorithm/)

## [cnblogs算法系列文章](https://www.cnblogs.com/huansky/p/13488234.html)

## [数据结构与算法](https://www.runoob.com/data-structures/data-structures-tutorial.html)

## [数据结构和算法](https://zhuanlan.zhihu.com/p/37289934)

## [数据结构教程](https://www.dotcpp.com/course/ds-start/)

## [14大算法专题](https://www.playoffer.cn/1356.html)

## [洛谷-有答案](https://www.luogu.com.cn/problem/list)

## 《算法面试精选100题》 题包：https://www.lintcode.com/collection/164/ 密码：dqs666
