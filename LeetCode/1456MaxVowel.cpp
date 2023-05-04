/*
1456. 定长子串中元音的最大数目
https://leetcode.cn/problems/maximum-number-of-vowels-in-a-substring-of-given-length/
https://leetcode.com/problems/maximum-number-of-vowels-in-a-substring-of-given-length/
*/
class Solution {
public:
    bool IsVowel(char c) {
        return c=='a' || c=='e' || c=='i' || c=='o' || c=='u';
    }

#if 0       //Good
    int maxVowels(string s, int k) {
        int maxLen;
        //deque<int> q(k);  //NOT reserve space
        deque<int> q;
        int i=0;

        for(; i<k; ++i) {
            if( IsVowel(s[i]) ) q.push_back(i);            
        }
        maxLen = q.size();
        
        //for(; i<(int)s.size()-k+1; ++i) {   //This should be right pointer
        for(; i<(int)s.size(); ++i) {   //This should be right pointer
            if(!q.empty() && q.front()<=i-k) q.pop_front();
            if( IsVowel(s[i]) ) q.push_back(i);

            //maxLen = std::max( maxLen, q.size() );
            if(q.size()>maxLen) maxLen = q.size();
        }
                
        return maxLen;
    }
#else   //Best
    int maxVowels(string s, int k) {
        int maxLen = 0;
        int r = 0;

        for(; r<k; ++r) {
            if( IsVowel(s[r]) ) ++maxLen;
        }

        int subMax = maxLen;
        for(; r<(int)s.size(); ++r) {
            if( IsVowel(s[r]) ) ++subMax;       //最原始的窗口思想-right/left pointer
            if( IsVowel(s[r-k]) ) --subMax;

            if(subMax>maxLen) maxLen = subMax;
        }

        return maxLen;
    }
#endif
};