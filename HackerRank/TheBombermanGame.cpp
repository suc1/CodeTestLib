/*
!!利用题目例子来调试!!
按照题目顺序， 第2秒种， 第3秒爆炸

不能计数加一同时爆破，因为"3211"会少算一格
爆破邻居增长方向为3不能爆破, 因为"3311"会少算一格

换一个思路: 比较两个矩阵算爆炸

//12 timeout
只有四种结果:
1. if(n<=1) return 原始grid
2. if n in [2,4,6,8...] 充满grid
3. if n in [3,7,11,15...]一种情况: 因为炸弹延时就两种情况，而且每次都充满
4. if n in [5,9,13,17...]一种情况
5. 情况3 & 4 是互补的，因为爆炸是+字, 爆炸充满两次就恢复原状
*/

#if 0       //12 timeout
vector<string> bomberMan(int n, vector<string> grid) {
    if(n<=1) return grid;
    
    int rowLen = grid.size();
    int colLen = grid[0].size();
    
    for(int i=0; i<rowLen; ++i) {
        for(int j=0; j<colLen; ++j) {
            if(grid[i][j]=='O') grid[i][j]='0';
        }
    }
                    
    for(int s=1; s<=n; ++s) {
        for(int i=0; i<rowLen; ++i) {
            for(int j=0; j<colLen; ++j) {
                if(grid[i][j]!='.') {
                    ++(grid[i][j]);
                }
            }       
        }
        
        if(s%2==0) {
            for(int i=0; i<rowLen; ++i) {
                for(int j=0; j<colLen; ++j) {
                    if(grid[i][j]=='.') grid[i][j]='0';
                }
            }            
        }
        
        for(int i=0; i<rowLen; ++i) {
            for(int j=0; j<colLen; ++j) {
                if(grid[i][j]>='3') {
                    grid[i][j] = '.';
                    if(i+1<rowLen) {
                        if(grid[i+1][j]!='3') grid[i+1][j] = '.';
                    }
                    if(i-1>=0) grid[i-1][j] = '.';
                        
                    if(j+1<colLen) {
                        if(grid[i][j+1] != '3') grid[i][j+1] = '.';
                    }
                    if(j-1>=0) grid[i][j-1] = '.';
                    }
            }       
        }
                
    }
    
    
    for(int i=0; i<rowLen; ++i) {
        for(int j=0; j<colLen; ++j) {
            if(grid[i][j]!='.') grid[i][j]='O';
        }
    }
    
    return grid;
}

#else
vector<string> Blast(const vector<string>& fullGrid, const vector<string>& grid) {
    vector<string> ret(fullGrid);
    int rowLen = ret.size();
    int colLen = ret[0].size();
    
    for(int i=0; i<rowLen; ++i) {
        for(int j=0; j<colLen; ++j) {
            if(grid[i][j]=='O') {
                ret[i][j] = '.';
                
                if(i+1<rowLen) ret[i+1][j] = '.';
                if(i-1>=0) ret[i-1][j] = '.';
                
                if(j+1<colLen) ret[i][j+1] = '.';
                if(j-1>=0) ret[i][j-1] = '.';
            }
        }
    }
    
    return ret;
}

vector<string> bomberMan(int n, vector<string> grid) {
    if(n<=1) return grid;
    
    vector<string> fullGrid(grid);
    for(auto& i : fullGrid) {
        for(int j=0; j<i.size(); ++j) i[j] = 'O';
    }
    
    if(n%2==0) return fullGrid;
    
    //if n in [3,7,11,15...]
    grid = Blast(fullGrid, grid);
    if(n%4==3) {
        return grid;    
    }
    
    //if n in [5,9,13,17...]
    grid = Blast(fullGrid, grid);
    return grid;
}
#endif
