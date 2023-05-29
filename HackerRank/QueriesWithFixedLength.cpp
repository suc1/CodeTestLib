/*
std::numeric_limits<int>::min();

测试数据:
5 1                 //n=5, 1 test case
33 11 44 11 55      //data
2                   //k=2

答案:33

测试步骤:
0  1  2  3  4       //index
33 11 44 11 55

队列:
0  1                //i = 0
2                   //i = 2
2  3                //i = 3
4                   //i = 4
*/
void PrintQue(int i, const deque<int> &qu) {
    cout << i << '=';
    for(int j : qu) cout << j << ',';
    cout << endl;
}

vector<int> solve(vector<int> arr, vector<int> queries) {
    vector<int> ret;
    int len = arr.size();
        
    for(int k: queries) {
        deque<int> qu;
        int _min = std::numeric_limits<int>::max();
        
        for(int i=0; i<k; ++i) {
            while(!qu.empty() && arr[ qu.back() ]<=arr[i]) qu.pop_back();
            qu.push_back(i);
        }
        if(_min > arr[qu.front()]) _min = arr[qu.front()];
        
                
        for(int i=k; i<len; ++i) {
            if(qu.front()<=i-k) qu.pop_front(); //To: swtich the order of below is wrong because the que maybe empty
            //or pop_back() error 
            while(!qu.empty() && arr[ qu.back() ]<=arr[i]) qu.pop_back();
            qu.push_back(i);
            
            if(_min > arr[qu.front()]) _min = arr[qu.front()];
        }
        ret.push_back(_min);
    }
    
    return ret;    
}
