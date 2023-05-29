/*
Flipping the Matrix
https://www.hackerrank.com/challenges/flipping-the-matrix/problem

先用4＊4的矩阵找出规律，避免思路错误

x轴表示的列
*/

#if 0   //思路错误
void ReverseRow(vector<vector<int>> &matrix, int row) {
    int len = matrix.size()/2;
    for(int i=0; i<len; ++i) {
        int tmp = matrix[row][i];
        matrix[row][i]= matrix[row][2*len-i-1];
        matrix[row][2*len-i-1] = tmp;        
    }
}

void ReverseCol(vector<vector<int>> &matrix, int col) {
    int len = matrix.size()/2;
    for(int i=0; i<len; ++i) {
        int tmp = matrix[i][col];
        matrix[i][col]= matrix[2*len-i-1][col];
        matrix[2*len-i-1][col] = tmp;        
    }
}

int flippingMatrix(vector<vector<int>> matrix) {
    int len = matrix.size();
    bool changed = false;

    do {
        for(int row=0; row<len; ++row) {
            int rowMax = 0;
            int col;
            for(col=0; col<len/2; ++col) rowMax -= matrix[row][col];
            for(; col<len; ++col) rowMax += matrix[row][col];
            
            if(rowMax>0) {
                ReverseRow(matrix, row);
                changed = true;
            }
        }

        for(int col=0; col<len; ++col) {
            int colMax = 0;
            int row;
            for(row=0; row<len/2; ++row) colMax -= matrix[row][col];
            for(; row<len; ++row) colMax += matrix[row][col];
            
            if(colMax>0) {
                ReverseCol(matrix, col);
                changed = true;
            }
        }
        changed = false;
    }while(changed);
    
    int sum = 0;
    for(int i=0; i<len/2; ++i)
        for(int j=0; j<len/2; ++j) sum+=matrix[i][j];
        
    return sum;
}
#else

int flippingMatrix(vector<vector<int>> matrix) {
    int len = matrix.size() / 2;
    int sum = 0;
    
    for(int row=0; row<len; ++row) {
        int refY = 2*len - row - 1;
        
        for(int col=0; col<len; ++col) {
            int refX = 2*len - col - 1;
            
            //ToDo: No template max(1, 2, 3, 4...)???
            sum += std::max( {matrix[row][col],
                matrix[row][refX],
                matrix[refY][col],
                matrix[refY][refX]} );
        }
    }        
        
    return sum;
}

#endif