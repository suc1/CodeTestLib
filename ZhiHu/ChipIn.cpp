/*
[凑钱](https://www.zhihu.com/question/23995189)
钞票面额分别是1、5、11

输出凑出w的方案: 记录从哪里来的

改写成“我到哪里去”: 求出f(x)之后，不直观
f(x+1)  = min{f(x)+1, f(x-4)+1, f(x-10)+1}
f(x+5)  = min{f(x)+1, f(x-6)+1}
f(x+11) = min{f(x)+1, f(x-10)+1}
*/

#include <iostream>
#include <limits>

#if 0
int main() {
    int n = 15;
    int f[n+1];
    f[0] = 0;

    for(int i=1; i<=n; ++i) {
        int cost = std::numeric_limits<int>::max();
        if(i>=1) cost = std::min(cost, 1+f[i-1]); 
        if(i>=5) cost = std::min(cost, 1+f[i-5]);
        if(i>=11) cost = std::min(cost, 1+f[i-11]);
        f[i] = cost;
    }

    for(int i=0; i<=n; ++i) std::cout << i << '=' << f[i] << std::endl;

    return 0; 
}
#else
int main() {
    int n = 15;
    int f[n+1];
    int from[n+1];
    f[0] = 0;

    for(int i=1; i<=n; ++i) {
        int cost = std::numeric_limits<int>::max();
        int fromWhere = 0;
        if(i>=1) {
            int j = 1+f[i-1];
            if(j<cost) {
                cost = j;
                fromWhere = i-1;
            }
        }
        if(i>=5) {
            int j = 1+f[i-5];
            if(j<cost) {
                cost = j;
                fromWhere = i-5;
            }
        } 
        if(i>=11) {
            int j = 1+f[i-11];
            if(j<cost) {
                cost = j;
                fromWhere = i-11;
            }
        }
        
        f[i] = cost;
        from[i] = fromWhere;
    }

    for(int i=0; i<=n; ++i) std::cout << i << '=' << f[i] << " From " << from[i] << std::endl;

    return 0; 
}
#endif