string pangrams(string s) {
    bool alphabet[26] = {false};
    
    for(char c : s) {
        int index; //'a' > 'A'
        if('a'<=c && c <= 'z') {
            index = c-'a';
            alphabet[index] = true;    
        } 
        if('A'<=c && c <= 'Z') {
            index = c-'A';
            alphabet[index] = true;    
        }
    }
    
    for(size_t i=0; i<sizeof(alphabet)/sizeof(alphabet[0]); ++i) {
        if(alphabet[i]==false) return "not pangram";
    }
    
    return "pangram";
}