/*
Input:
4
aab
aac
aacghgh
aabghgh

My answer:
BAD SET
aabghgh

Right answer:
BAD SET
aacghgh


通用算法: 两层循环，第一回答"BAD SET"对，但是串不对，说明处理次序不对
"from a-j"条件没用上
*/

/* [Trie字典树/前缀树](https://zhuanlan.zhihu.com/p/28891541)
典型应用是用于统计和排序大量的字符串
优点是：利用字符串的公共前缀来减少查询时间，最大限度地减少无谓的字符串比较

前缀树的3个基本性质：
1. 根节点不包含字符，除根节点外每一个节点都只包含一个字符。
2. 从根节点到某一节点，路径上经过的字符连接起来，为该节点对应的字符串。
3. 每个节点的所有子节点包含的字符都不相同。
*/

/*
they want the first word that is either a prefix of a previous word 
or has a previous word as a prefix.
So the order at which it is given counts

Build a trie:
1. If you pass a letter that is the end of another word, return "BAD".
2. If you end on a letter that already exists, return "BAD"

但是C++没有trie现成函数，实现方法:
1. [自己实现trie, 工作量大](https://www.digitalocean.com/community/tutorials/trie-data-structure-in-c-plus-plus)
2. 使用两个集合: 一个是所有子串集合，对应别人是自己的前缀。另一个是全串集合，对应自己是别人的前缀
*/

#if 0 //Answer order is wrong
bool Prefix(const string& s1, const string&s2, bool& switchPos) {
    size_t len = s1.size();
    if(len>s2.size()) {
        len = s2.size();
        switchPos = true;
    } else {
        switchPos = false;
    }
    
    for(size_t i=0; i<len; ++i) {
        if(s1[i]!=s2[i]) return false;
    }
    
    return true;
}

void noPrefix(vector<string> words) {
    for(size_t i=0; i<words.size(); ++i) {
        for(size_t j=i+1; j<words.size(); ++j) {
            bool switchPos = false;
            if(Prefix(words[i], words[j], switchPos)) {
                cout << "BAD SET" << endl << words[switchPos ? i : j] << endl;
                return;
            }
        }
    }
        
    cout << "GOOD SET" << endl;
}
#else
void noPrefix(vector<string> words) {
    std::set<string> part, full;
    
    for(string i : words) {
        auto it = part.find(i);
        if(it!=part.cend()) {
            cout << "BAD SET" << endl << i << endl;
            return;
        }
        
        for(size_t j=1; j<=i.size(); ++j) {     //j<=i.size()
            string subStr = i.substr(0, j);
            auto it = full.find(subStr);
            if(it!=full.cend()) {
                cout << "BAD SET" << endl << i << endl;
                return;
            }
            
            part.insert(subStr);
        }
        full.insert(i);
    }
    
    cout << "GOOD SET" << endl;
}
#endif