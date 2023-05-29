#if 1
int pageCount(int n, int p) {
    int from1 = p/2;
    int fromEnd = n/2-from1;
    return min(from1, fromEnd);    
}
#else
int pageCount(int n, int p) {
    int n2= n/2;
    if(p<=n2) {     //local is complex, so it is not good for interview
        return p/2;    
    }
    else return n2 - p/2;
}
#endif