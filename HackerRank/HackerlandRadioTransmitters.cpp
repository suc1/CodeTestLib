/*
覆盖范围是K，则左右总覆盖范围是 2*K+1
但是发射台需要装在某个房顶上，所以不能采用简单的总覆盖范围来计算
*/
#if 0   //19 tests failed
int hackerlandRadioTransmitters(vector<int> x, int k) {
    std::sort(x.begin(), x.end());
    k = k*2+1; //Two sides
    
    int ret = 0;
    size_t i = 0;
    while(i<x.size()) {
        size_t j=i+1;
        while(j<x.size()) {
            if(x[j]>x[i]+k) break;
            ++j;
        }
        i = j;
        ++ret;
    }
    
    return ret;
}
#else
int hackerlandRadioTransmitters(vector<int> x, int k) {
    std::sort(x.begin(), x.end());
    
    int ret    = 0;
    size_t i   = 0;
    size_t len = x.size();
    while(i<len) {
        size_t j=i+1;
        while(j<len) {
            if(x[j]>x[i]+k) {
                --j;
                break;
            }
            ++j;
        }
        
        //Find the middle to install transmitter
        /*if(j>=len-1) {
            ++ret;
            return ret;
        }*/
        i=j;
        ++j;
        while(j<len) {
            if(x[j]>x[i]+k) {
                break;
            }
            ++j;
        }
        i=j;
        ++ret;
    }
    
    return ret;
}
#endif
