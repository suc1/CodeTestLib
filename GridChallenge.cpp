/*
二维数组，
最里面的元素也是一维数组，内存连续，把它当成X轴
外面的一维数组，把它当成Y轴

访问最里面的元素[Y轴][X轴], 一层层剥皮
*/

string gridChallenge(vector<string> grid) {
    for(auto& st : grid) {
        std::sort(st.begin(), st.end());        
    }
    
    for(size_t i=0; i<grid[0].size(); ++i) {
        for(size_t j=1; j<grid.size(); ++j) {
            if(grid[j][i]<grid[j-1][i]) return "NO";
        }
    }
    
    return "YES";
}