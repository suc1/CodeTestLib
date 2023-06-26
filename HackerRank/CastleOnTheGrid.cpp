/*
实现行列坐标系
--------->y
|
|
V
x

第一想法是宽度优先搜索BFS/queue，工作量大


通用解法工作量大， 但是利用字符矩阵，并利用步数数字，方便调试 (最少内存是是否访问过的矩阵)
'..X..'    '44X45'
'....X'    '3323X'
'XX.X.' -> 'XX2X1'
'.....'    '11110'
'.X..X'    '2X22X'

两种写法都行:
qu.push( tuple<int, int, int>(startX, startY, 0) );
qu.push( std::make_tuple(startX, startY, 0) );
*/

/*
[图搜索算法：DFS、BFS、GBFS、Dijkstra、A*](https://zhuanlan.zhihu.com/p/346666812)
1. 区别在于openlist所选用的数据结构类型: 栈, 队列, 优先队列
2. **无权图:**
2.1 深度优先搜索(DFS), 使用栈/递归, 快速找到一条路径(弹出栈的队列), 但是可能不是最优解
2.2 广度优先搜索(BFS), 使用队列/循环, 能找到最优路径(从终点回溯，沿父节点走到头), 但是慢
3. 贪婪最佳优先算法(GBFS)，属于BFS, 使用优先队列(Priority Queue), 用来提高搜索效率，但是不能确保找到最优路径
4. **带权图: 代价函数F(n)**
5. Dijkstra算法, 是BFS在带权图中的扩展
6. A*算法，是在Dijkstra中加入启发函数得到的算法，兼顾效率和完备性

代价函数:
1. GBFS用节点到目标点的距离作为代价函数，将搜索方向引向目标点，搜索效率高, g(n)
2. Dijkstra算法采用起点到当前扩展节点的移动代价作为代价函数，能够确保路径最优, h(n)
3. A*算法: f(n) = g(n) + h(n)
4. A*算法: 如果大部分情况下 h(n) < g(n), 则能找到最优路径。
4. 由于A* 算法的启发函数是位置上的距离，因此在不带位置信息的图数据中不适用

图搜索算法的基本流程如下：
1. 创建一个容器，一般称为openlist，用来存储将要访问的节点
2. 将起点加入容器
3. 开始循环：
3.1 弹出：从容器中取出一个节点
3.2 扩展：获取该节点周围没有访问过的节点，处理并判断是否到达终点。将这些节点放入容器

图搜索算法的基本数据如下：
1. openlist，用来存储将要访问的节点
2. 没访问到的点的集合
3. 带权图: 每点的最小代价

图搜索算法的标出路径:
1. DFS: 弹出栈的队列
2. BFS: 从终点回溯，沿父节点走到头

邻接矩阵n*n, 邻接表
*/
void Debug(const vector<string> &grid) {
    for(auto i: grid) {
        cout << i << endl;
    }
    cout << endl;
}

int minimumMoves(vector<string> grid, int startX, int startY, int goalX, int goalY) {
    grid[startX][startY] = '0';
    //Debug(grid);
    
    queue< std::tuple<int, int, int> > qu;  //x, y, step
    qu.push( std::make_tuple(startX, startY, 0) );
    while(!qu.empty()) {
        int x, y, step;
        std::tie (x, y, step) = qu.front();
        qu.pop();
        ++step;
        char stepChar = std::to_string(step)[0];
        
        for(int i = x; i<(int)grid.size(); ++i) {
            if(grid[i][y]=='.') {
                if(i==goalX && y==goalY) return step;
                       
                qu.push( std::make_tuple(i, y, step) );
                grid[i][y] = stepChar;
            } else if(grid[i][y]=='X') break;
        }
        
        for(int i = x; i>=0; --i) {
            if(grid[i][y]=='.') {
                if(i==goalX && y==goalY) return step;
                       
                qu.push( std::make_tuple(i, y, step) );
                grid[i][y] = stepChar;
            } else if(grid[i][y]=='X') break;
        }
        
        //y
        for(int i = y; i<(int)grid[x].size(); ++i) {
            if(grid[x][i]=='.') {
                if(x==goalX && i==goalY) return step;
                       
                qu.push( std::make_tuple(x, i, step) );
                grid[x][i] = stepChar;
            } else if(grid[x][i]=='X') break;
        }
        
        for(int i = y; i>=0; --i) {
            if(grid[x][i]=='.') {
                if(x==goalX && i==goalY) return step;
                       
                qu.push( std::make_tuple(x, i, step) );
                grid[x][i] = stepChar;
            } else if(grid[x][i]=='X') break;
        }
        
        //Debug(grid);
    }
    
    return -1;
}
