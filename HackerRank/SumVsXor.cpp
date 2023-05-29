#if 0   //4 timeout
long sumXor(long n) {
    int ret = 0;
    for(long x=0; x<=n; ++x) {
        if( (n+x) == (n^x) ) ++ret;
    }
    
    return ret;
}
#else   //bit 0 有2个选择: 0，1; bit 1 只有1个选择: 0 
long sumXor(long n) {
    long sum = 1;
    while(n>0) {
        if(n%2==0) sum *= 2;
        n /= 2;
    }
    
    return sum;
}

#endif