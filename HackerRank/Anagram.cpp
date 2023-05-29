/*
https://www.hackerrank.com/test/3fmlgi1ase7/questions/bae9p3effgk

*/
int anagram(string s) {
    int len = s.size();
    if(len%2) return -1;
    //cout << s << endl;
    
    map<char, int> a;
    for(int i=0; i<len/2; ++i) {
        map<char, int>::iterator it = a.find(s[i]);
        if(it==a.end()) {
            a[ s[i] ]= 1;
        } else {
            ++(it->second);
        }
    }
    
    map<char, int> b;
    for(int i=len/2; i<len; ++i) {
        map<char, int>::iterator it = b.find(s[i]);
        if(it==b.end()) {
            b[ s[i] ]= 1;
        } else {
            ++(it->second);
        }
    }
    
    int sum = 0;
    for( auto ita = a.begin(); ita!=a.end(); ++ita) {
        auto itb = b.find(ita->first);
        if(itb!=b.end()) {
            //ita = a.erase(ita) will get trouble???
            if(ita->second > itb->second)
            {
                ita->second -= itb->second;
                sum += ita->second;
            }
        } else {
            sum += ita->second;
        }
    }
    
    return sum;
    
}
