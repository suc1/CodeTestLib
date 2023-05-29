int getTotalX(vector<int> a, vector<int> b) {
    int lenA = a.size();
    int lenB = b.size();
    
    int ret = 0;
    bool good = true;
    for(int i= a[lenA-1]; i<=b[0]; ++i) {
        good = true;
        
        for(int j=0; j<lenA; ++j) {
            if(i%a[j]!=0) {
                good = false;
                break;
            }
        }
        if(!good) continue;
        
        for(int j=0; j<lenB; ++j) {
            if(b[j]%i!=0) {
                good = false;
                break;
            }
        }
        if(!good) continue;
        //cout << i << endl;
        
        ++ret;
    }
    
    return ret;
}
