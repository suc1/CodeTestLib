/*
最终是一个排序
!!尽量一次交换，两个位置都换好!!

根据排序一一交换，得不到最小值

为什么这种交换会浪费???
*/

/* [Minimum swap required to Sort an Array](https://www.youtube.com/watch?v=-2_c4lG7k_M)
1. !!带着索引排序!!，(1)保留了起始和最终序列的信息, (2)避免了后面的n^2查找
2. `--i`非常重要。保证了不漏
3. 为什么这种就是最小值?????
*/

/* !!!卡在这里!!!
正序和倒序都符合要求，取Swap最小值
*/

#if 0
size_t Find(const vector<int> &arr, size_t start, int value) {
    while(start<arr.size()) {
        if(arr[start]==value) return start;
        ++start;
    }
    
    return 0;
}

int lilysHomework(vector<int> arr) {
    vector<int> sorted(arr);
    std::sort(sorted.begin(), sorted.end());
    int ret = 0;
    
    for(size_t i=0; i<arr.size(); ++i) {
        if(sorted[i]!=arr[i]) {
            //cout << i << ',' << sorted[i] << ',' << arr[i] << endl;
            size_t j = Find(arr, i+1, sorted[i]);
            std::swap( arr[i], arr[j] );
            ++ret;
        }
    }
    
    return ret;
}
#else
bool PairGreater(const pair<int, int>& i, const pair<int, int>& j) {
    return i.first > j.first;    
}

int SwapMin(const vector<int> &arr, bool min2Max) {
    vector< pair<int, int> > s(arr.size());
    for(size_t i=0; i<arr.size(); ++i) s[i] = {arr[i], i};
    
    if(min2Max) std::sort(s.begin(), s.end() );
    else std::sort(s.begin(), s.end(), PairGreater );
            
    int swap=0;
    for(size_t i=0; i<s.size(); ++i) {
        if((int)i!=s[i].second) {
            ++swap;
            std::swap(s[i], s[ s[i].second ]);
            --i;            //import
        }
    }
    
    return swap;    
}

int lilysHomework(vector<int> arr) {
    int max = SwapMin(arr, true);
    int maxReverse = SwapMin(arr, false); 
    return std::min(max, maxReverse);
}

#endif