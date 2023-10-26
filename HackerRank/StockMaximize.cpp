/*
1. 如果一直升，只买不卖，最后到最高点卖出。
如果一直降，不买，最后到最低点开始买入。

问题转化成找出上升段

但是0=5, 1=4, 2=3, 3=4, 4=5，应该从1=4开始买，而不是从2=3

2.把上升段向前延伸算法有缺陷，涉及两个段的融合

3. 求最大值，注意最大值可能有多个，尾巴的最大值单独算
3.1 最大值前面的点只买入，到最大值卖出
3.2 删掉前面段，对后面段重复计算
3.3 std::heap???
3.4 思路完全错误: 后面的Test case失败

4. 如果现在的价格比将来的最大值低, 买入. 在将来的最大值处卖掉
4.1 从前向后扫描, 有许多重复计算
4.2 从后向前扫描最好
*/

void Debug(const char* explain, const vector<int> seg) {
    cout << explain;
    for(int i: seg) cout << i << ',';
    cout << endl;
}

#if 0
vector<int> GetUpSegment(const vector<int> &prices) {
    vector<int> seg;
    int flag = 0; //-1=down, 0=unknow, 1=up
    
    for(int i=1; i<(int)prices.size(); ++i) {
        if(prices[i]>prices[i-1]) {
            if(flag==0 || flag==-1) {
                flag = 1;
                seg.push_back(i-1);
            }
        } else if(prices[i]<prices[i-1]) {
            if(flag==1) {
                flag = -1;
                seg.push_back(i-1);
            }
        }
    }
    
    int i = prices.size()-1;
    if(prices[i]>prices[i-1]) seg.push_back(i);            
       
    Debug("GetUpSegment=", seg);
    
    return seg;
}

void ExpandSegment(vector<int> &seg, const vector<int> &prices) {
    for(int i=0; i<(int)seg.size(); i+=2) {
        //How to merge two segment
    }
}

long stockmax(vector<int> prices) {
    vector<int> seg = GetUpSegment(prices);
    ExpandSegment(seg, prices);
    
    long profit = 0;
    for(int i=1; i<(int)seg.size(); i+=2) {
        int num  = seg[i]-seg[i-1];
        long cost = 0;
        for(int j=seg[i-1]; j<seg[i]; ++j) cost+=prices[j];
        profit += num * prices[ seg[i] ] - cost;
    }
    
    return profit;
}
#elif 0
long Segment(vector<int> &prices) {
    vector<int>::iterator maxIt = std::max_element(prices.begin(), prices.end());
    int num = 0;
    long cost =0;
    
    for(vector<int>::iterator it=prices.begin(); it!=maxIt; ++it) {
        ++num;
        cost += *it;
    }
    
    long profit =  num * (*maxIt) - cost;
    
    ++maxIt;       //erase() Not delete last one
    prices.erase(prices.begin(), maxIt);
    
    return profit;    
}

long stockmax(vector<int> prices) {
    long ret = 0;
    while(prices.size()>=2) {
        ret += Segment(prices);
        //Debug("seg=", prices);
    }
    
    return ret; 
}
#else
long stockmax(vector<int> prices) {
    long profit = 0;
    int curMax = prices[ prices.size()-1 ];
    
    for(int i=prices.size()-2; i>=0; --i) {
        if(prices[i]>curMax) curMax = prices[i];
        else profit += curMax - prices[i];
    }
    
    return profit;
}
#endif