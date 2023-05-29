/*
vector 只有尾部push_back(), pop_back()，没有头部
*/
int SumStack(const vector<int> &h) {
    int sum =0;
    
    for(auto it: h) {
        sum += it;    
    }
        
    return sum;
}

int equalStacks(vector<int> h1, vector<int> h2, vector<int> h3) {
    std::reverse(h1.begin(), h1.end());
    std::reverse(h2.begin(), h2.end());
    std::reverse(h3.begin(), h3.end());
    
    int s1 = SumStack(h1);
    int s2 = SumStack(h2);
    int s3 = SumStack(h3);
    
    while(s1!=s2 || s1!=s3 || s2!=s3) {
        vector<int> *pMax = &h1;
        int max = s1;
        int maxIndex = 1;
        
        if(max<s2) {
            pMax = &h2;
            max = s2;
            maxIndex = 2;
        }
        if(max<s3) {
            pMax = &h3;
            max = s3;
            maxIndex = 3;
        }
        
        //cout << maxIndex << ",top=" << pMax->back() << endl;
        int popTop = pMax->back();
        pMax->pop_back();
        
        #if 0       //20 timeout
        s1 = SumStack(h1);
        s2 = SumStack(h2);
        s3 = SumStack(h3);
        #else
        switch (maxIndex) {
            case 1:
                s1 -= popTop;
                break;
            case 2:
                s2 -= popTop;
                break;
            case 3:
                s3 -= popTop;
                break;
        }
        #endif
    }
    
    return s1;
}
