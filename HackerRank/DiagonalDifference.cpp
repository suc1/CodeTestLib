int diagonalDifference(vector<vector<int>> arr) {
    int row = arr.size();
    int col = arr[0].size();
    assert(row == col);
    
    int sum =0, sum2=0;
    for(int i=0; i<row; ++i){
            sum += arr[i][i];
            sum2 += arr[i][row-1-i];
        }
    
    return abs(sum-sum2); 
}
