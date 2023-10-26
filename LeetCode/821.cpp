#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<int> shortestToChar(string s, char c) {  //Time Limit Exceeded
        vector<int> ret( s.size() );

        //case 0: left is not c
        int left  = 0;
        if(s[0]!=c) {
            int right = findNext(s, c, 0);
            
            while(left<=right) {
                ret[left] = right-left;
                ++left;
            }

            left = right;
        }
                
        //case 1: right is not c
        int right2 = s.size()-1;
        if(s[ s.size()-1 ]!=c) {
            int left2 = findPrev(s, c, right2);
            
            while(left2<=right2) {
                ret[left2] = right2-left2;
                ++left2;
            }

            right2 = left2;
        }
        //cout << "left=" << left << ", right2=" << right2 << endl;

        //case 2: [left, right2]=[c...c]
        int right;
        do {
            right = findNext(s, c, left);
            cout << "\nleft2=" << left << ", right=" << right << endl;
            
            int mid = (left+right)/2;
            int start = 0;
            while(left<mid) {
                ret[left] = start;
                ++start;
                ++left;
            }

            if((left+right)%2==0) {
                ret[left] = start;
                ++left;
            }
                            
            while(left<=right) {
                ret[left] = start;
                --start;
                ++left;
            }
            --left;
            //cout << "left3=" << left << ", right=" << right << ",mid=" << mid << endl;
            
            cout << "right=" << right << ",right2=" << right2 << endl;
        } while(right<right2);
        
        return ret;
    }

    int findNext(const string &s, char c, int startIndex) {
        for(int i=startIndex+1; i<s.size(); ++i) if(s[i]==c) return i;
        return -1;
    }

    int findPrev(const string &s, char c, int startIndex) {
        for(int i=startIndex-1; i>0; --i) if(s[i]==c) return i;
        return -1;
    }
};

int main() {
    Solution s;
    vector<int>  ret = s.shortestToChar("loveleetcode", 'e');

    return 0; 
}