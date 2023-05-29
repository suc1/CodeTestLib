void Sum(const vector<int> &arr, int med, int &left, int &right) {
    left  = 0;
    right = 0;
    
    int len = arr.size();
    if(len==1) return;
    
    for(int i=0; i<med; ++i) left += arr[i];
    for(int i=med+1; i<len; ++i) right += arr[i];
}

#if 0       //2 timeout
string balancedSums(vector<int> arr) {
    int left =0, right=0;
    int len = arr.size();
    
    for(int med=0; med<len; ++med) {
        Sum(arr, med, left, right);
        if(left==right) {
            return "YES";
        }
    }
    
    return "NO";
}
#else
string balancedSums(vector<int> arr) {
    int left =0, right=0;
    int len = arr.size();
    
    Sum(arr, 0, left, right);
    if(left==right) {
        return "YES";
    }
        
    for(int med=1; med<len; ++med) {
        left += arr[med-1];
        right -= arr[med];
        if(left==right) {
            return "YES";
        }
    }
    
    return "NO";
}

#endif
