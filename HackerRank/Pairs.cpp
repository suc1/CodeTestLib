bool Find(const vector<int>& arr, int start, int find) {
    for(int i=start; i<arr.size(); ++i) {
        if(arr[i]==find) return true;
    }
    
    return false;
}

int pairs(int k, vector<int> arr) {
    std::sort(arr.begin(), arr.end());
    
    int num=0;
    for(int i=0; i<arr.size(); ++i) {
        int diff = arr[i] + k;
        if(Find(arr, i+1, diff)) ++ num;
    }
    
    return num;
}