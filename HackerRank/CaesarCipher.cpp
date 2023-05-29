string caesarCipher(string s, int k) {
    string ret="";
    for(char c : s) {
        if('a'<=c && c<='z') {
             c = (c-'a'+k) % 26;
             c += 'a';
        } else if('A'<=c && c<='Z') {
             c = (c-'A'+k) % 26;
             c += 'A';
        }
        ret += c;
    }
    
    return ret;
}