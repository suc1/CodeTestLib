vector<int> icecreamParlor(int m, vector<int> arr) {
    vector<int> ret;
    
    for(int i=0; i<arr.size(); ++i) {
        int left = m - arr[i];
        for(int j=i+1; j<arr.size(); ++j) {
            if(left==arr[j]) {
                ret.push_back(i+1);
                ret.push_back(j+1);
                
                return ret;
            }
        }
    }
    
    return ret;    
}