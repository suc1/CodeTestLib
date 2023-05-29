int superDigit(long m) {
    if(m<10) return (int)m;
    
    long sum = 0;
    while(m>10) {
        sum += m % 10;
        m /= 10;
    }
    sum += m;
    
    return superDigit(sum);
}

int superDigit(string n, int k) {
    long sum = 0;           //int will overflow
    for(char c : n) {
        sum += c - '0';
    }
    
    sum = sum * k;
    return superDigit(sum);
}