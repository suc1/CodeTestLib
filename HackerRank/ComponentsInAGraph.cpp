/*
求连通图，宽度遍历最好; 
深度遍历差一些，容易栈溢出
visit一见就设置，不影响深度遍历，因为已经在递归里面

此题是求连通图的顶点数
1. 每访问一个节点+1
2. 数在队列里面出现的节点数

求两点之间的路径数 = 顶点数-1
1. 每访问一个节点+1
2. 每个节点带路径数: pair(vertex, road+1)
3. BreasthFirstSearch.cpp 

怎么使用条件: 两列分隔，列间连接，列内不连接
1. 减少一半的计算量[1, n/2]

Union-Find算法
*/
int BFS(int i, const vector< vector<int> > &table, bool *visit) {
    queue<int> qu;
    qu.push( i );
    int vertex = 1;
            
    while(!qu.empty()) {
        for(int j : table[ qu.front() ]) {
            if(!visit[j]) {
                visit[j] = true;
                qu.push(j);
                ++vertex;
                //if(i==1) cout << j <<endl;
            }
        }
        qu.pop();
    }
    
    return vertex;
}

void Debug(const vector< vector<int> > &table) {
    for(size_t i=0; i<table.size(); ++i) {
        cout << "table=" << i << ':';
        for(auto j: table[i]) {
            cout << j << ' ';
        }
        cout << endl;
    }     
}

vector<int> componentsInGraph(vector<vector<int>> gb) {
    int pointMax = 0;
    for(auto i: gb) {
        if(pointMax<i[0]) pointMax=i[0];
        if(pointMax<i[1]) pointMax=i[1];
    }
    
    ++pointMax; //start from 0
    vector< vector<int> > table(pointMax);
    for(auto i: gb) {
        table[ i[0] ].push_back( i[1] );
        table[ i[1] ].push_back( i[0] );
    }
    //Debug(table);
    
    
    bool visit[pointMax] = {false};
    int minCom=std::numeric_limits<int>::max(), maxCom=0;   //Todo: replace ret
        
    for(int i=0; i<=pointMax/2; ++i) {
        if(!visit[i]) {
            visit[i] = true;
            int vertex = BFS(i, table, visit);
            //cout << i <<',' << vertex << endl;
            if(vertex>=2) {
                if(minCom>vertex) minCom=vertex;
            if(maxCom<vertex) maxCom=vertex;    
            }            
        }
    }
    
    vector<int> ret = {minCom, maxCom};
    return ret;
}
