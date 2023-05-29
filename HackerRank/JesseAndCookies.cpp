/*
从只取最小的两个元素，就应该想到std::priority_queue

使用std::heap也行, 代码多一些, 但是少一次复制. 
怎么使用priority_queue移动构造???
*/
#if 0 //11 timeout
bool IsEnough(int k, const vector<int>& A) {
    if(A.size()==0) return true;
    
    return A[0]>=k;
}

int cookies(int k, vector<int> A) {
    std::sort(A.begin(), A.end());
    if(IsEnough(k, A)) return 0;
    
    int num=1;
    while(A.size()>=2) {
        int i = A[0] + 2 * A[1];
        A[0] = i;
        A.erase( A.begin()+1);
        
        std::sort(A.begin(), A.end());
        if(IsEnough(k, A)) return num;
        
        ++num;
    }
    
    //if(A[0]>=k) return num;
    return -1;
}
#else   //std::priority_queue

int cookies(int k, vector<int> A) {
    //priority_queue<int> q(A.begin(), A.end());  //[12, 10, 9]
    priority_queue<int, std::vector<int>, std::greater<int> > q( A.begin(), A.end() );
    //cout << q.top() << endl;
        
    int num = 0;
    while(q.size()>=2) {
        int i = q.top();
        if(i>=k) return num;
        
        q.pop();
        i += 2 * q.top();
        q.pop();
        
        q.push(i);
        ++num;
    }
    
    if(q.top()>=k) return num;
    return -1;
}
#endif
