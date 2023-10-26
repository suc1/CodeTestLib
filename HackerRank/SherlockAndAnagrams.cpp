/*
首先想到分成大小相同的子串，判断字母个数相等. 使用map，代码复杂
如果使用窗口，可能能简单一些??

https://www.youtube.com/watch?v=nIM75-CIZWg
10:00
*/

bool isPermutation(const string& m1, const string& m2) {    
    if (m1 == m2) 
        return true;
    return false;
}

vector<string> sortedSubstrs(int k, const string& s) {
    vector<string> sorted_substrs;
    string substr;
    for (auto i = 0; i < s.size() - k + 1; i++) {
        substr = s.substr(i, k);
        sort(substr.begin(), substr.end());
        sorted_substrs.push_back(substr);
    }
    return sorted_substrs;
}

int sherlockAndAnagrams(string s) {    
    int equal_anagram_count = 0;
    for (int k = 1; k < s.size(); k++) {
        auto sorted_substrs = sortedSubstrs(k, s);
        for (int i = 0; i < s.size() - k; i++) {            
            for (int j = i + 1; j < s.size() - k + 1; j++) {                
                if (isPermutation(sorted_substrs[i], sorted_substrs[j])) {
                    equal_anagram_count++;
                }                
            }
        }
    }
    return equal_anagram_count;
}