/*
图算法入门1：基础表示方法和深度优先搜索实现
https://blog.csdn.net/fangfanglovezhou/article/details/124966585

class Graph {
    public:
        struct Node {
            int name;
            vector<int> link;
            
            bool visit = false;
            //Others
        };

    public:
        vector< Node > m_graph;
};

1. 邻接表表示法: 二维矩阵
2. 深度优先:    只能用使用递归实现.     宽度优先: 只能使用队列实现
3. 使用visit，因为是图可能循环. 最好放在Node内
4. 针对的是连通图的情况. 若不连通，从没访问的节点开始重复
*/

#include <vector>
#include <iostream>

#include <string.h>

using namespace std;

class Graph {
    public:
        struct Node {
            char name;          //ToDo: replace char with template
            vector<char> link;
            
            bool visit = false;
            //Others
        };

    public:
        vector< Node > m_graph;

    public:
        Graph();
        void DFS();
        void DFS(char name);
    
    //Helper function
    public:
        void PrintGraph();
    private:
        Node& FindNode(char name);
};

Graph::Graph() {
    const char *input[] = { //data from csdn
        "sai",      //顶点  边 边 ...
        "asbceg",
        "gahi",
        "igs",
        "hg",
        "bacde",
        "eabf",
        "fe",
        "db",
        "cab"        
    };

    Node node;
    int len = sizeof(input)/sizeof(input[0]);
    for(int i=0; i<len; ++i) {
        node.name = input[i][0];
        m_graph.push_back(node);

        int edgeLen = strlen(input[i]);
        for(int j=1; j<edgeLen; ++j) m_graph.back().link.push_back( input[i][j] );
    }

}

void Graph::DFS() {
    Node startNode = m_graph[0];
    //startNode.visit = true;       //must set in child
    //cout << startNode.name;
    DFS(startNode.name);    
}

void Graph::DFS(char name) {
    Node& node = FindNode(name);
    if(node.visit) return;

    node.visit = true;
    cout << name;

    for(auto it : node.link) {
        DFS(it);
    }
    cout << endl;
}

Graph::Node& Graph::FindNode(char name) {
    for(auto& it : m_graph) {
        if(it.name==name) return it;
    }

    return m_graph[0];
}

void Graph::PrintGraph() {
    for(size_t i=0; i<m_graph.size(); ++i) {
        cout << m_graph[i].name << "->";
        for(size_t j=0; j<m_graph[i].link.size(); ++j) {
            cout << m_graph[i].link[j] <<' ';
        }
        cout << endl;
    }
}

int main() {
    Graph g;
    //g.PrintGraph();
    g.DFS();
    
    return 0;
}
