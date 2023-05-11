/*
图算法入门2:宽度优先搜索实现
https://blog.csdn.net/fangfanglovezhou/article/details/125219018

See graphDepth.cpp
宽度优先: 只能使用队列实现
*/
#include <vector>
#include <iostream>
#include <queue>

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
    
        void BFS();
        //void BFS(queue<Node&> &q, char name);   //error????
        void BFS(queue<Node*> &q, char name);
    //Helper function
    public:
        void PrintGraph();
    private:
        Node& FindNode(char name);
        Node* FindNodePtr(char name);
};

Graph::Graph() {
    #if 0
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
    #else
    const char *input[] = { //Same data as csdn to get the same result: "sabgcdehif"
        "sa",
        "asbg",
        "gahi",
        "ig",
        "hg",
        "bacde",
        "ebf",
        "fe",
        "db",
        "cb"              
    };
    #endif

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

#if 0
void Graph::BFS() {
    Node& startNode = m_graph[0];
    queue<Node&> q;
    q.push(startNode);

    BFS(q, startNode.name);    
}

void Graph::BFS(queue<Graph::Node&> &q, char name) {
    while(!q.empty()) {
        Node &cur = q.front();
        q.pop();
        if(cur.visit) continue; //duplicate

        cur.visit = true;
        cout << cur.name;
        for(auto it : cur.link) {
            Node &child = FindNode(it);
            if(child.visit) continue;

            q.push(child);
        }
    }
}
#else
void Graph::BFS() {
    Node* startNode = &m_graph[0];
    queue<Node*> q;
    q.push(startNode);

    BFS(q, startNode->name);    
}

void Graph::BFS(queue<Graph::Node*> &q, char name) {
    while(!q.empty()) {
        Node *cur = q.front();
        q.pop();
        if(cur->visit) continue; //duplicate

        cur->visit = true;
        cout << cur->name;
        for(auto it : cur->link) {
            Node *child = FindNodePtr(it);
            if(child->visit) continue;

            q.push(child);
        }
    }
}
#endif
Graph::Node& Graph::FindNode(char name) {
    for(auto& it : m_graph) {
        if(it.name==name) return it;
    }

    return m_graph[0];
}

Graph::Node* Graph::FindNodePtr(char name) {
    for(size_t i=0; i<m_graph.size(); ++i) {
        if(m_graph[i].name==name) return &m_graph[i];
    }

    return &m_graph[0];
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
    //g.DFS();
    g.BFS();
    
    return 0;
}
