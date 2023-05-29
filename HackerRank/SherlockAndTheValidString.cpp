string isValid(string s) {
    map<char, int> map1;
    for(char c : s) {
        auto it = map1.find(c);
        if(it==map1.end()) {
            map1[c] = 1;
        } else {
            ++(it->second);
        }
    }
    
    int freq1 = 0, freq2 = 0;
    int num1  = 0,  num2 = 0;
    for(auto it : map1) {
        if(freq1==0) freq1 = it.second;
        if(freq1==it.second) {
            ++num1;
            continue;
        }
        
        if(freq2==0) freq2 = it.second;
        if(freq2==it.second) {
            ++num2;
            continue;
        }
        
        return "NO";
    }
    
    if(freq2==0) return "YES";
    
    //delete 1 char
    if(num1==1) {
        if(freq1==1) return "YES";
        if(freq1==freq2+1) return "YES";
    }
    if(num2==1) {
        if(freq2==1) return "YES";
        if(freq2==freq1+1) return "YES";
    }
    
    return "NO";
    
}