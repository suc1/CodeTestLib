/*
Kadane算法: 最大子数列问题
https://baike.baidu.com/item/%E6%9C%80%E5%A4%A7%E5%AD%90%E6%95%B0%E5%88%97%E9%97%AE%E9%A2%98
https://zh.wikipedia.org/wiki/%E6%9C%80%E5%A4%A7%E5%AD%90%E6%95%B0%E5%88%97%E9%97%AE%E9%A2%98

算法描述：
1. 遍历该数组， 在遍历过程中， 将遍历到的元素依次累加起来， 当累加结果小于或等于0时， 从下一个元素开始，重新开始累加。
2. 累加过程中， 要用一个变量(max_so_far)记录所获得过的最大值
3. 一次遍历之后， 变量 max_so_far 中存储的即为最大子片段的和值。

代码实现:
def max_subarray(A):
    max_ending_here = max_so_far = A[0]
    for x in A[1:]:
        max_ending_here = max(x, max_ending_here + x)   //下一步x，两个选择: （1）x作为队尾，（2）x作为队头
        max_so_far = max(max_so_far, max_ending_here)
    return max_so_far

变种是：
1. 如果数列中含有负数元素，允许返回长度为零的子数列
2. 寻找数列中最大乘积序列，且要求序列中，相邻元素间隔不超过限定值等
*/

/*
subsequence as any subset of an array
subarray as a contiguous subsequence in an array
*/
bool IsAllNeg(const vector<int> &arr) {
    for(int i: arr) {
        if(i>0) return false;
    }
    
    return true;
}

int GetSubsequence(const vector<int> &arr) {
    int sum = 0;
    for(int i: arr) {
        if(i>0) sum+=i;
    }
    
    return sum;
}

#if 0   //1 timeout
int GetSubarray(const vector<int> &arr) {   //contiguous
    int max = 0;
    for(int l=0; l<arr.size(); ++l) {
        for(int r=l+1; r<=arr.size(); ++r) {       //must r<=arr.size()
            int subMax = 0;
            for(int k=l; k<r; ++k) subMax+=arr[k];
            if(max<subMax) max = subMax;
        }
    }
    
    return max;
}
#else
int GetSubarray(const vector<int> &arr) {   //contiguous
    int max    = arr[0];
    int maxEnd = arr[0];
    
    for(size_t i=1; i<arr.size(); ++i) {
        maxEnd = std::max(arr[i], maxEnd+arr[i]);
        max = std::max(max, maxEnd);
    }
    
    return max;
}
#endif

vector<int> maxSubarray(vector<int> arr) {
    vector<int> ret(2);
    if(IsAllNeg(arr)) {
        int max = *std::max_element(arr.begin(), arr.end());
        ret[0] = max;
        ret[1] = max;
        return ret;
    }
    
    ret[0] = GetSubarray(arr);
    ret[1] = GetSubsequence(arr);
    return ret;
}





bool IsAllNeg(const vector<int> &arr) {
    for(int i: arr) {
        if(i>0) return false;
    }
    
    return true;
}

int GetSubsequence(const vector<int> &arr) {
    int sum = 0;
    for(int i: arr) {
        if(i>0) sum+=i;
    }
    
    return sum;
}

int GetSubarray(const vector<int> &arr) {   //contiguous
    int max    = arr[0];
    int maxEnd = arr[0];
    
    for(size_t i=1; i<arr.size(); ++i) {
        maxEnd = std::max(arr[i], maxEnd+arr[i]);
        max = std::max(max, maxEnd);
    }
    
    return max;
}

vector<int> maxSubarray(vector<int> arr) {
    vector<int> ret(2);
    if(IsAllNeg(arr)) {
        int max = *std::max_element(arr.begin(), arr.end());
        ret[0] = max;
        ret[1] = max;
        return ret;
    }
    
    ret[0] = GetSubarray(arr);
    ret[1] = GetSubsequence(arr);
    return ret;
}