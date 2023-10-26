/*
两个newEnergy式子是一样的, newEnergy = botEnergy * 2 - height
从这个式子，从后向前计算最好

E(n) = 2^n * x(0) - 2^(n-1) * h(1) - 2^(n-2) * h(2) - h(n)
这个归纳式子，反倒弄麻烦了
*/

int chiefHopper(vector<int> arr) {
    float ret = 0;
    for(int i = arr.size()-1; i>=0; --i) {
        ret = std::ceil( (ret + arr[i])/2 );
    }
    
    return int( ret );
}
