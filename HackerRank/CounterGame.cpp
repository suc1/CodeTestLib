long Power2(long i) {
    long j=1;
    while(i>=2) {
        i /= 2;
        j *= 2;
    }
    
    return j;
}

string counterGame(long n) {
    //if(n==1) return "Richard";
    bool Louise = true;
    
    while(n>=2) {
        long p2 = Power2(n);
        if(p2==n) n/=2;
        else {
            n -= p2;
        }
        Louise = ! Louise;
    }
    
    if(Louise) return "Richard";
    return "Louise";
}
