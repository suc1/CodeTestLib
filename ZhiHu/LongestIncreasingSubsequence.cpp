/*
[最长上升子序列](https://www.zhihu.com/question/23995189)

将原来的dp数组的存储由数值换成该序列中，上升子序列长度为i的上升子序列，的最小末尾数值
[O( n*ln(n) )](https://www.luogu.com.cn/blog/pks-LOVING/junior-dynamic-programming-dong-tai-gui-hua-chu-bu-ge-zhong-zi-xu-lie)
*/
#include <iostream>

int main() {
    int arr[] = {1, 5, 3, 4, 6, 9, 7, 8};
    int len = sizeof(arr)/sizeof(arr[0]);
    int lis[len];
    lis[0] = 1;
    
    for(int i=1; i<len; ++i) {
        int max = 0;
        for(int j=0; j<i; ++j) {
            if(arr[i]>=arr[j]) max = std::max(max, lis[j] + 1);
            else max = std::max(max, lis[j]);
        }
        lis[i] = max;
    }

    for(int i=0; i<len; ++i) std::cout << i << '=' << lis[i] << std::endl;

    return 0;
}