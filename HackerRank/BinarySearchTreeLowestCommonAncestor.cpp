/*
LCA（Least Common Ancestors），最近公共祖先
有根树,; 无向无环图，而LCA(T,u,v)即u到v的最短路上深度最小的点
[LCA算法 ](https://www.cnblogs.com/morui/p/10792566.html)

1. 暴力枚举（朴素算法）: 
利用深度信息: 首先将u，v中深度较深的那一个点向上蹦到和深度较浅的点，然后两个点一起向上蹦

2. 如果是二叉查找树: 
分三种情况考虑: 都在左边; 都在右边; 一左一右

3. DFS:
两个点的LCA一定是两个点在DFS序中出现的位置之间深度最小的那个点

4. 倍增寻找（ST算法）

*/
/*
题目描述误导是一颗普通二叉树, 但是编程接口是真正的二叉查找树
To use the test data, you will have to create the binary search tree yourself.
Here on the platform, the tree will be created for you.
*/

Node *lca(Node *root, int v1,int v2) {
	int u,v;
    if(v1<v2) {
        u=v1;
        v=v2;
    } else {
        u=v2;
        v=v1;
    }
        
    Node *cur=root;
    while(cur!=nullptr) {
        if(cur->data>v) {
            cur = cur->left;
        } else if(cur->data<u) {
            cur = cur->right;
        } else return cur;    
    }
                
    return nullptr;
}
