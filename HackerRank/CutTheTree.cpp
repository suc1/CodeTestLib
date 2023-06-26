/*[Cut the Tree](https://www.hackerrank.com/challenges/cut-the-tree/forum)
第一想到:
1. 建立树
2. 从底向上，记录子树的总和
3. 从头开始搜索，选取分支
4. 问题是: 最小答案是否在最小分支里面???
5. 代码量大

下面第一种方法:
1. cumulative记录子树的总和. 没有建立树，而且一次DFS就计算出整个cumulative
2. 找最小剪枝使用BFS
3. `cumulative[0]-cumulative[next]`计算两个剪枝的差
4. `if(cumulative[0]-cumulative[next]<v) search.push(next)`减少一半搜索范围, `v`是总树和的一半
5. `candidates`保存两个剪枝的差

recursive DFS will fail,  iterative DFS can work???
*/
#if 0
int dfs(int* cumulative, bool* visited , vector<int>* edges, const vector<int>& data , const size_t& n, const int& current_node){
    cumulative[current_node] += data[current_node];
    visited[current_node]=true;
    for(auto& c : edges[current_node]){
        if(!visited[c]){
            visited[c]=true;
            cumulative[current_node] += dfs(cumulative, visited, edges, data, n, c);
        }
    }
    return cumulative[current_node];
}

int cutTheTree(vector<int> data, vector<vector<int>> edges) {
    vector<int> candidates;
    vector<int>* adjancylist = new vector<int>[data.size()];
    int* cumulative=new int[data.size()]{};
    bool* visited=new bool[data.size()]{};
    for(auto& c : edges){
        adjancylist[c[0]-1].push_back(c[1]-1);
        adjancylist[c[1]-1].push_back(c[0]-1);
    }

    //dfs
    dfs(cumulative, visited, adjancylist, data, data.size(), 0);

    const int v = cumulative[0]/2;
    for(int i=0; i<data.size(); i++) visited[i]=false;
    queue<int> search;
    search.push(0);
    visited[0]=true;
    while(!search.empty()){
        int cur_node=search.front();
        search.pop();
        for(auto& next: adjancylist[cur_node]){
            if(!visited[next]){
                visited[next]=true;
                candidates.push_back( cumulative[0]-cumulative[next] );
                if(cumulative[0]-cumulative[next]<v) search.push(next);
            }
        }
    }
    
    for_each(candidates.begin(), candidates.end(), [&cumulative]( int& e){
        e=abs(cumulative[0]-2*e); 
    });
    delete[] adjancylist;
    delete[] visited;
    delete[] cumulative;
    return *(min_element(candidates.begin(), candidates.end()));
}
#else
int DFS(int *sum, bool *visit, const vector<int> &data, const vector<vector<int>> &table, int curPt) {
    sum[curPt] += data[curPt];
    
    for(auto i: table[curPt]) {
        if(!visit[i]) {
            visit[i]=true;
            sum[curPt] += DFS(sum, visit, data, table, i);
        }
    }
    
    return sum[curPt];
}

void DebugArray(const char* explain, const int *sum, int len) {
    cout << explain;
    for(auto i=0; i<len; ++i) cout << sum[i] << ',';
    cout << endl;    
}
void DebugArray(const char* explain, const vector<int> sum) {
    cout << explain;
    for(auto i: sum) cout << i << ',';
    cout << endl;    
}

int cutTheTree(vector<int> data, vector<vector<int>> edges) {
    int len = (int)data.size();
    vector< vector<int> > table(len);
    for(auto i: edges) {
        table[ i[0]-1 ].push_back( i[1]-1 );
        table[ i[1]-1 ].push_back( i[0]-1 );
    }
    
    int sum[len] = {0};
    bool visit[len] = {false};
    visit[0] = true;
    DFS(sum, visit, data, table, 0);
    //DebugArray("sum=", sum, len);
    
    for(int i=1; i<len; ++i) visit[i] = false;  //visit[0] = true
    queue<int> qu;
    qu.push(0);
    int half = sum[0]/2;
    vector<int> diff;
    
    while(!qu.empty()) {
        for(auto i: table[ qu.front() ]) {
            if(visit[i]==false) {
                visit[i] = true;
                //cout << "sum[0]=" << sum[0] << ", sum[i]=" << sum[i] << ",i=" << i << endl;
                //if( sum[0] - sum[i]<half )
                diff.push_back( abs(sum[0] - sum[i] - sum[i]) );
                qu.push(i);
            }
        }
        qu.pop();
    }
    
    //DebugArray("diff=", diff);
    return *std::min_element( diff.begin(), diff.end() );
}
#endif