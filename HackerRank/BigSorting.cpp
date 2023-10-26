/*
comp()是实现<. 如果==返回 true 会Segmentation Fault???
https://www.hackerrank.com/challenges/big-sorting/problem
*/
/*
std::qsort() 是C
std::sort() 是C++

comp()升序默认是 <
*/
#if 1
bool comp(const string& s1, const string& s2) {
    size_t len1 = s1.size();
    size_t len2 = s2.size();
    
    if(len1<len2) return true;
    if(len1>len2) return false;
    
    for(size_t i=0; i<len1; ++i) {
        if(s1[i]<s2[i]) return true;
        if(s1[i]>s2[i]) return false;
    }
    
    return false;       //== //true: case 3,4,6 will Segmentation Fault
}
#elif 0     //ok
bool comp(const string& s1, const string& s2) {
    size_t len1 = s1.size();
    size_t len2 = s2.size();
    
    if(len1==len2) {
        for(size_t i=0; i<len1; ++i) {
            if(s1[i]<s2[i]) return true;
            if(s1[i]>s2[i]) return false;
        }
        return false; // return true will "Segmentation Fault"       
    }
    
    return(len1<len2);
}
#elif 0     //ok, Why????
bool comp(const string& s1, const string& s2) {
    size_t len1 = s1.size();
    size_t len2 = s2.size();
    
    if(len1==len2) {
        return s1<s2; 
    }
    
    return(len1<len2);
}
#else
bool comp(const string& s1, const string& s2) {
    return ((s1.size() == s2.size()) ? (s1 < s2) : (s1.size() < s2.size()));
}
#endif

void PrintVector(const vector<string> &s) {
    cout << "str begin" << endl;
    for(auto i : s) cout << i << endl;    
    cout << "str end" << endl;
}

vector<string> bigSorting(vector<string> unsorted) {
    PrintVector(unsorted);
    
    std::sort(unsorted.begin(), unsorted.end(), comp);
    
    return unsorted;    
}