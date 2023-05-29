/*
 Dense Ranking: 密集排名: （1）排名是连续的  （2）允许并列第几

 此题特点:
 1. 排名表ranked不变，只读，分数从大到小
 2. 选手得分player参照排名表得出排名，不加入排名表
 3. player>=ranked[0], 得出排名为1
 4. 设ranked长度为LenRanked, player==ranked[ LenRanked-1 ], 得出排名为LenRanked
 5. 如果player<ranked[ LenRanked-1 ], 得出排名为 LenRanked+1
 6. 中间段: 如果player in ranked(i, i+1], 即小于ranked[i]大于等于ranked[i+1]，得出排名为 i+1
*/
#if 0
//4 timeout
int BinarySearch(const vector<int>& board, int find) { //return pos start from 0
    if(find>=board[0]) return 0;
    
    int i;
    int len = board.size(); 
    for(i=1; i<len; ++i) {
        if(find<board[i-1] && find>=board[i]) return i;
    }
    
    return i;
}
#else
int BinarySearch(const vector<int>& board, int find) { //return pos start from 0
    //borad = [100 50 40 20 10], Big -> Small
    int l =0;
    int r = board.size()-1;
    
    while(l<r-1) {
        int m = (l+r)/2;
        if(find == board[m]) return m;
        
        if(find>board[m]) r=m;
        else l = m;
    }
    //cout << l << ',' << r << ',' << find << endl;
    
    if(find>=board[l]) return l;
    if(find>=board[r]) return r;
    return r+1;
} 
#endif

vector<int> climbingLeaderboard(vector<int> ranked, vector<int> player) {
    //remove duplated
    vector<int> board;
    for(int i : ranked) {
        if(board.empty()) {
            board.push_back(i);
        } else {
            if(i != board.back()) board.push_back(i);
        }
    }
    
    vector<int> ret;
    for(int i : player) {
        int j = BinarySearch(board, i) + 1;
        ret.push_back(j);        
    }
    
    return ret;
}
