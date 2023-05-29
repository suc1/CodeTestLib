long flippingBits(long n) {
    //cout << sizeof(int) << endl; //4
    unsigned long reverse = 0xffffffff;
    
    return (long)(((unsigned long)n) ^ reverse ); 
}
