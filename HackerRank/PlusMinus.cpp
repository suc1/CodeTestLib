void plusMinus(vector<int> arr) {
    int pos = 0;
    int zero = 0;
    int neg = 0;
    
    for(auto it : arr) {
        if(it>0) ++pos;
        else if(it==0) ++zero;
        else ++neg;
    }
    
    float len = (float)arr.size();
    
    std::cout << std::fixed << std::setprecision(6) << pos/len << endl;
    std::cout << std::fixed << std::setprecision(6) << neg/len << endl;
    std::cout << std::fixed << std::setprecision(6) << zero/len << endl;
}
