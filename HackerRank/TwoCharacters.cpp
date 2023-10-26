string GetLetterList(const string &s) {
    string ret;
    ret += s[0];
    
    for(int i=1; i<s.length(); ++i) {
        if(ret.find_first_of( s[i] )==std::string::npos) ret += s[i];
    }
    
    return ret;    
}

int AlterLetter(const string &s, char c1, char c2) {
    int ret = 0;
    int i;
    char prev;
    for(i=0; i<s.length(); ++i) {
        if(s[i]==c1) {
            prev = c1;
            ++ret;
            break;
        } else if(s[i]==c2) {
            prev = c2;
            ++ret;
            break;
        }
    }
    
    ++i;    //!!!
    for(; i<s.length(); ++i) {
        if(s[i]==c1) {
            if(prev == c1) return 0;
            prev = c1;
            ++ret;
        } else if(s[i]==c2) {
            if(prev == c2) return 0;
            prev = c2;
            ++ret;
        }
    }
    
    return ret;
}

int alternate(string s) {
    string letters = GetLetterList(s);
    //cout << letters << endl;
    
    int ret = 0;
    for(int i=0; i<letters.length(); ++i) {
        for(int j=i+1; j<letters.length(); ++j) {
            int res = AlterLetter(s, letters[i], letters[j]);
            //cout << letters[i] << ',' << letters[j] << ',' << res << endl;
            if(res>ret) ret = res; 
        }
    }
    
    return ret;
}