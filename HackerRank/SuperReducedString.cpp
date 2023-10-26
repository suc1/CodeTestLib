string superReducedString(string s) {
    bool changed;
    do {
        changed = false;
        for(int i=0; i<s.size()-1; ++i) {
            if(s[i]==s[i+1]) {
                s.erase(i, 2);
                changed = true;
                break;
            }
        }
        
    } while(changed==true && s.size()>1);
    
    if(s.size()==0) return "Empty String";
    return s;
}
