/*
得使用大数库
https://github.com/983/Num/blob/master/num.hpp
*/

int fibonacciModified(int t1, int t2, int n) {
    //cout << t1 << ',' << t2 << ',';
    for(int i=t2; i<n-1; ++i) {
        int t3 = t1 + t2 *t2;
        //cout << t3 << ',';
        t1=t2;
        t2=t3;        
    }
    
    return t2;
}
