/*  
1. 暴力破解关键: 下一个数 = i+1, 丑数判定 
2.
3. 高效关键: 寻找下一个丑数. 它是前面某个丑数乘2, 乘3, 乘5.
4. 过程: 开始老队列只有1，新生成的队列是2，3，5。去重加入老队列
5. 老队列是1, 2, 3, 5. 取第二个数2，循环4
6.
7. 怎样去重的Merge Sort? (1)一一枚举来去重 (2) 加入
8.
9. 第一思路: 使用vector来实现
10. 第二思路: 使用现成数据结构:
11. queue不能中间插队，不合适
12. priority_queue不能一一枚举来去重，不合适???
13. C++最小堆: std::priority_queue< int, std::vector<int>, std::greater<int> > minHeap;
14. C++最小堆手动实现: heap和vector合作可以
15. make_heap(), pop_heap(), push_heap()
16. pop_heap()把最大元素放在vector最后面，需要和vector合作
17. 但是觉得最小堆手动实现也挺麻烦！！！
18.
19. 1364: 430467210 = 0x19A8 688A
20. 1665:1898437500 = 0x7127 DB7C
21. 因为排序了，溢出变成负数影响排序
22. 
23. Best: 
*/

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    /**
     * @param n: An integer
     * @return: return a  integer as description.
     */
    int nthUglyNumber(int n) {
        // write your code here
        vector<unsigned long> ret = {1};
        int pos = 0;

        while(pos<n) {
            MergeSort(ret, pos);
            ++pos;
        }

        PrintVector(ret);
        return ret[n-1];
    }

    void MergeSort(vector<unsigned long> &ret, int startPos) {
        const int len = 3;
        unsigned long newNum[len] = {ret[startPos]*2, ret[startPos]*3, ret[startPos]*5};
        
        int i = FindInsertPosition(ret, startPos+1, newNum[0]);
        if(i==-1) {
            ret.push_back( newNum[0] );
            ret.push_back( newNum[1] );
            ret.push_back( newNum[2] );
            return;
        } else if(i>=0) {
            ret.insert(ret.begin()+i, newNum[0]);
        } else i = startPos+1;

        int j = FindInsertPosition(ret, i, newNum[1]);
        if(j==-1) {
            ret.push_back( newNum[1] );
            ret.push_back( newNum[2] );
            return;
        } else if(j>=0) {
            ret.insert(ret.begin()+j, newNum[1]);
        } else j = i;

        int k = FindInsertPosition(ret, j, newNum[2]);
        if(k==-1) {
            ret.push_back( newNum[2] );
            return;
        } else if(k>=0) {
            ret.insert(ret.begin()+k, newNum[2]);
        }
    }

    //return -1: add to tail; -2: duplicate
    int FindInsertPosition(const vector<unsigned long> &ret, int startPos, unsigned long value) {
        while(startPos<ret.size() && ret[startPos]<value) ++startPos;
        
        if(startPos>=ret.size()) return -1;
        if(ret[startPos]==value) return -2;
        return startPos;
    }

    void PrintVector(const vector<unsigned long> &p) {
        //for(int i=0; i<p.size(); ++i) cout << i << ':' << p[i] << endl;
        for(int i=1660; i<1670; ++i) cout << i << ':' << p[i] << endl;
        /*for(int i=0; i<1670; ++i) {
            if(p[i]<=0) {
                cout << i << ':' << p[i] << endl;
                break;
            }
        }*/
    }
};

int main() {
    Solution s;
    s.nthUglyNumber(1665);
}