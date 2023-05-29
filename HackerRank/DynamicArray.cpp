vector<int> dynamicArray(int n, vector<vector<int>> queries) {
    vector< vector<int> > arr(n);
    vector<int> ret;
    int lastAnswer = 0;
    
    for(auto& it : queries) {
        if(it[0]==1) {  //1 x y
            int idx = (it[1]^lastAnswer) % n;
            arr[idx].push_back( it[2] );    
        } else {
            int idx = (it[1]^lastAnswer) % n;
            lastAnswer = arr[ idx ][ it[2] % arr[idx].size() ];
            ret.push_back(lastAnswer);
        } 
    }
    
    return ret;
}