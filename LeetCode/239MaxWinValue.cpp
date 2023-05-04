/*
239. 滑动窗口最大值
Same as //hackerRank/DequeStl.cpp
https://leetcode.cn/problems/sliding-window-maximum/
https://leetcode.com/problems/sliding-window-maximum/

关键: 因为要保留最大值，Que中比当前元素小的元素无意义
1. Que头是最大值
2. 如果Que头移出去Window，pop
3. 把Que中比当前元素小的元素pop出去, 只处理尾部
4. !!当前元素一定要进入队列!!

特点:
1. 线性时间复杂度: 将一部分问题中的嵌套循环转变为一个单循环，因此它可以减少时间复杂度. (通过旧有的计算结果对搜索空间进行剪枝，这样便减少了重复计算)
2. 主要应用在数组和字符串
3. 请找到满足 xx 的最 x 的区间（子串、子数组）的 xx
4. 窗口的构造是很重要

例子:
9 4 2 3 4

que=
push i=0, arr[i]=9
que=0,

que=0,      //after pop 
push i=1, arr[i]=4
que=0,1,

max=9 
que=1,
push i=2,arr[i]=2
que=1,2,

max=4 
que=    //after pop
push i=3,arr[i]=3
que=3,

max=3 
que=    //after pop
push i=4,arr[i]=4
que=4,

max=4
*/
#if 0
class Solution {    //14 timeout
public:
    int MaxWindow(const vector<int>& nums, int left, int right) {
        int maxV = nums[left++];
        
        while(left<=right) {
            maxV = max(maxV, nums[left++]);
        }
        return maxV;
    }

    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        vector<int> res;
        int right = k;
        int maxVal = MaxWindow(nums, 0, k-1);
        res.push_back(maxVal);

        while( right<(int)nums.size() ) {
            int temp = MaxWindow(nums, right-k+1, right);
            res.push_back(temp);
            ++right;
        }

        return res;
    }
};
#else
/*
采用两步: 1.先把窗口填满， 2.窗口开始滑动
而且使用deque
做题速度快，而且容易Bug Free
*/
class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        deque<int> q(k);
        int i=0;
        for(; i<k; ++i) {
            while(!q.empty() && nums[q.back()]<=nums[i]) q.pop_back();
            q.push_back(i);
        }

        vector<int> res;
        for(; i<(int)nums.size(); ++i) {
            res.push_back( nums[q.front()] );
            if(q.front()<=i-k) q.pop_front();

            while(!q.empty() && nums[q.back()]<=nums[i]) q.pop_back();
            q.push_back(i);
        }

        res.push_back( nums[q.front()] );
        return res;
    }
};
#endif
