/*
分段是连续的，简单很多
*/
int birthday(vector<int> s, int d, int m) {
    int way = 0;
    for(size_t i=0; i<=s.size()-m; ++i) {
        int sum = 0;
        for(int j=0; j<m; ++j) sum += s[i+j];
        if(sum==d) ++way;
    }
    
    return way;
}
