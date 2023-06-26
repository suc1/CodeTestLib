/*
1. 如果建路成本c_road >= 建图书馆c_lib，每个城市建一个图书馆
2. 否则: 把整个图分成独立连通子图-极大连通子图
3. 此题是无权图
*/
/*[求图的连通子图](https://www.feiniaomy.com/post/21448.html)
DFS或BFS
*/
/*
Union-Find (Disjoint-Set) data structure
*/

/*
一一求图的连通子图  代码量大

此题使用DFS, 求遍历的边即可
1. 准备边表
2. 重点是求遍历的边的总和: 递归的次数 = 遍历的点数, 注意 DFS::cost, `long cost = 1`代表每递归一次，顶点数加1

???有6个Test Case没过???
*/
long DFS(int i, const vector< vector<int> > &edgeTable, bool *visit) {
    visit[i] = true;
    long cost = 1;

    for(int j: edgeTable[i]) {
        if(!visit[j]) {
            visit[j] = true;
            cost += DFS(j, edgeTable, visit); 
        }
    }
    
    //cout << "i=" << i << ", total=" << total << endl;
    return cost;
}

void Debug(const vector< vector<int> > &edgeTable) {
    for(size_t i=0; i<edgeTable.size(); ++i) {
        std::cout << i << ':';
        for(int j: edgeTable[i]) std::cout << j << ' ';
        std::cout << endl; 
    }
    cout << endl;
}

long roadsAndLibraries(int n, int c_lib, int c_road, vector<vector<int>> cities) {
    if(c_road>=c_lib) return n*c_lib;
    
    vector< vector<int> > edgeTable(n);
    for(int i=0; i<(int)cities.size(); ++i) {
        edgeTable[ cities[i][0]-1 ].push_back( cities[i][1]-1 );
        edgeTable[ cities[i][1]-1 ].push_back( cities[i][0]-1 );
    }
    //Debug(edgeTable);
    
    bool visit[n] = {false};
    long sum = 0;
    for(int i=0; i<n; ++i) {
        if(!visit[i]) {
            //cout << "point=" << i << endl;
            visit[i] = true;
            sum += (DFS(i, edgeTable, visit)-1) * c_road + c_lib;
        }
    }
   
    return sum;
}