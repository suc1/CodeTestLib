#if 0
breadth first search 宽度
Depth-first search   深度

图退出条件: 因为不是树，有可能死循环，
图宽度搜索: 不太适合递归， 这里利用队列queue. !!!函数参数传深度是递归的思想!!!

犯过的错误:
1. 虽然是最短路径，但是是按宽度优先情况下，只是避免转圈循环, 记录第一次碰到这个节点深度就行了
2. 由于求路径，需要记录深度，只能在入队列前记录深度. 如果进入队列后深度需要+1麻烦多了(可能在队列中处理两个层次，不好划界)
3. 如果这一层都没有进队列，不要增加深度
4. 节点从1开始，把它-1， 和序号一样从0开始，减少麻烦
5. 孩子的深度 = 父亲的深度 +1， 不要使用全局变量!!!(可能在队列中处理两个层次，不好划界)
6. 有人使用边访问过删除的方法，避免采用visit (!!!代码简洁多了!!!)(副作用是无法复用)
6.1 但是由于边是双向的，已经访问的节点会再次入队列。所以计算深度需要判断如果深度是原始值才需要更新
6.2 还是使用visit
7. 等权图宽度搜索，第一次碰到的深度 不一定 是最小值！！！如果是树对，但是这是图(和Visit矛盾)
7.1 因为这是队列，同一批压入深度相同（点，深度）:（2， 1），（3，1），根到节点3的最小深度是1
7.2 但是下一批处理节点(2, 1)，如果它连接到3，深度为2。节点3没有访问，入列。队列是（3, 1）, (3, 2)
7.3 紧接着处理（3，1）节点3标记为已访问，但是(3,2)已经在队列中，不影响处理节点(3,2)
7.4 所以需要取最小值: 设置节点访问的时序非常重要
7.5 !!!教训: 一访问到立即置位，避免重复入队列, 而且再不超时!!!
7.6 图形是三角形

!!!!!!倒数第二个执行方法，代码简洁，但是有一个TimeOut case5, 原因是7.5重复入队列!!!!!

求连通图的节点数ComponentsInAGraph.cpp
#endif

#include <vector>
#include <iostream>
#include <queue>

#include <string.h>

using namespace std;

#if 0
class Graph {
    public:
        struct Node {
            //int name;
            vector<int> link;
            
            bool visit = false; //ToDo: remove it
            int  path = 0; //shortest
        };

    public:
        vector< Node > m_graph;

    public:
        Graph(int n, int m, vector<vector<int>> edges);
    
        vector<int> BFS(int start);
        void BFS(queue<int> &q, int depth);
    
    //Helper function
    public:
        void PrintGraph();
};

Graph::Graph(int n, int m, vector<vector<int>> edges) {
    Node node;
    for(int i=0; i<n; ++i) {
        m_graph.push_back(node);
    }
    
    for(int i=0; i<m; ++i) {
        int from = edges[i][0];
        int to = edges[i][1];
        m_graph[from-1].link.push_back(to);
        m_graph[to-1].link.push_back(from);
    }
}

vector<int> Graph::BFS(int s) {
    queue<int> q;             //Node* is Ok
    q.push(s);

    //记录深度在入队列前最好
    //m_graph[s-1].path = 0;
    m_graph[s-1].visit = true;
    
    BFS(q, 0);

    vector<int> path;
    for(size_t i=0; i<m_graph.size(); ++i) {
        if(i==s-1) continue;

        int num;
        if(m_graph[i].path==0) num = -1;
        else num = m_graph[i].path * 6;
        path.push_back(num);
    }

    return path;
}
void Graph::BFS(queue<int> &q, int depth) {
    int curDep = depth;
    while(!q.empty()) {
        int topIndex = q.front();
        Node &cur = m_graph[ topIndex-1 ];
        q.pop();
        cout << "cur" << topIndex << ",depth=" << curDep << endl;
        
        ++curDep;       //应该这个层次所有节点都处理完才能 +1
        bool thisLayerHasChild = false;
        for(auto it : cur.link) {
            Node &child = m_graph[it-1];
            if(child.visit) {
                continue;
            }
            thisLayerHasChild = true;
            //记录深度在入队列前最好
            child.visit = true;
            child.path = curDep;
            q.push( it );
        }
        if(!thisLayerHasChild) --curDep;
    }
}

vector<int> bfs(int n, int m, vector<vector<int>> edges, int s) {
    Graph g(n, m, edges);
    return g.BFS(s);
}

#elif 0

class Graph {
    public:
        struct Node {
            //int name;
            vector<int> link;   //=0 mean visit
            int  path = 0;      //shortest
        };

    public:
        vector< Node > m_graph;

    public:
        Graph(int n, int m, vector<vector<int>> edges);
    
        vector<int> BFS(int start);
        void BFS(queue<int> &q);
    
    //Helper function
    public:
        void PrintGraph();
};

Graph::Graph(int n, int m, vector<vector<int>> edges) {
    Node node;
    for(int i=0; i<n; ++i) {
        m_graph.push_back(node);
    }
    
    for(int i=0; i<m; ++i) {
        int from = edges[i][0] - 1;
        int to = edges[i][1] - 1;
        m_graph[from].link.push_back(to);
        m_graph[to].link.push_back(from);
    }
}

vector<int> Graph::BFS(int s) {
    queue<int> q;             //Node* is Ok
    q.push(s-1);

    BFS(q);

    vector<int> path;
    for(size_t i=0; i<m_graph.size(); ++i) {
        if(i==s-1) continue;

        int num;
        if(m_graph[i].path==0) num = -1;
        else num = m_graph[i].path * 6;
        path.push_back(num);
    }

    return path;
}

void Graph::BFS(queue<int> &q) {
    while(!q.empty()) {
        int topIndex = q.front();
        Node &parent = m_graph[ topIndex ];
        q.pop();
        
        for(auto it : parent.link) {
            Node &child = m_graph[it];
            if(child.path==0) child.path = parent.path + 1; //但是由于边是双向的，已经访问的节点会再次入队列
            q.push( it );
        }
        parent.link.clear();
    }
}

vector<int> bfs(int n, int m, vector<vector<int>> edges, int s) {
    Graph g(n, m, edges);
    return g.BFS(s);
}
#elif 0
void Debug(const vector<int> &v) {
    for(auto i : v) {
        cout << i << ' ';
    }
    cout << endl;
}

vector<int> bfs(int n, int m, vector<vector<int>> edges, int s) {
    //cout << "n=" <<n << " m=" << m << " s=" << s <<endl; 
    vector<vector<int>> table(n);
    for(size_t i=0; i<edges.size(); ++i) {
        table[ edges[i][0]-1 ].push_back( edges[i][1]-1 );
        table[ edges[i][1]-1 ].push_back( edges[i][0]-1 );
    }
    
    vector<int> ret(n, -1);
    bool v[n] = {false};
    queue< pair<int,int> > qu;  //pair(vetex, layer)
    qu.push( std::make_pair(s-1, 0) );
    
    while(!qu.empty()) {
        auto cur = qu.front();
        v[cur.first] = true;
        if(ret[cur.first]==-1) ret[cur.first] = cur.second;
        else ret[cur.first] = min(ret[cur.first], cur.second);
        
        for(auto j : table[cur.first]) {
            if(!v[j]) {
                qu.push( std::make_pair(j, cur.second+6));
            }
        }
        qu.pop();
    }
    
    //Debug(ret);
    ret.erase( ret.begin()+s-1 );
    return ret;    
}
#else 
void Debug(const vector<int> &v) {
    for(auto i : v) {
        cout << i << ' ';
    }
    cout << endl;
}

vector<int> bfs(int n, int m, vector<vector<int>> edges, int s) {
    //cout << "n=" <<n << " m=" << m << " s=" << s <<endl; 
    vector<vector<int>> table(n);
    for(size_t i=0; i<edges.size(); ++i) {
        table[ edges[i][0]-1 ].push_back( edges[i][1]-1 );
        table[ edges[i][1]-1 ].push_back( edges[i][0]-1 );
    }
    
    vector<int> ret(n, -1);
    bool v[n] = {false};
    v[s-1] = true;
    queue< pair<int,int> > qu;  //pair(vertex, road+1)
    qu.push( std::make_pair(s-1, 0) );
    
    while(!qu.empty()) {
        auto cur = qu.front();
        ret[cur.first] = cur.second;
                
        for(auto j : table[cur.first]) {
            if(!v[j]) {
                qu.push( std::make_pair(j, cur.second+6));
                v[j] = true;
            }
        }
        qu.pop();
    }
    
    //Debug(ret);
    ret.erase( ret.begin()+s-1 );
    return ret;    
}
#endif
