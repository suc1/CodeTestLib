/*
//1 Week Preparation Kit/Day 3/Mock Test
palindrome Index
https://www.hackerrank.com/test/crlnp8rgs12/questions/a2b68fq8p7b
*/
/*
fvyqxqxynewuebtcuqdwyetyqqisappmunmnldmkttkmdlnmnumppasiqyteywdquctbeuwenyxqxqyvf
0123456789012345678901234                               4321098765432109876543210

第一种解法返回24，这是正确的答案
TestCase5返回25，也是正确的答案, 因为是两个相同的qq
*/
#include <bits/stdc++.h>

using namespace std;

string ltrim(const string &);
string rtrim(const string &);



/*
 * Complete the 'palindromeIndex' function below.
 *
 * The function is expected to return an INTEGER.
 * The function accepts STRING s as parameter.
 */

#if 0           //Timeout
bool palindrome(const string &s) {
    int i = 0;
    int j = (int)s.size()-1;
    
    while(i<j) {
        if(s[i]!=s[j]) return false;
        ++i;
        --j;
    }
    
    return true;
}

bool palindromeIndex(const string &s, int remove) {
    int i = 0;
    int j = (int)s.size()-1;
    
    while(i<j) {
        if(i==remove) ++i;
        else if(j==remove) --j;
        
        if(s[i]!=s[j]) return false;
        ++i;
        --j;
    }
    
    return true;
}

int palindromeIndex(string s) {
    if(palindrome(s)) return -1;
    
    for(int i=0; i<(int)s.size(); ++i) {
        if (palindromeIndex(s, i)) return i;
    }
    
    return -1;
}

#elif 0     //Using next element to judge palindrome is NOT enought

int palindromeIndex(string s) {
    int i = 0;
    int j = (int)s.size()-1;
    
    int delIndex = 0;
    int delNum   = 0;
    
    while(i<j) {
        if(s[i]==s[j]) {
            ++i;
            --j;
            continue;    
        }
        
        if(s[i+1]==s[j]) {
            ++delNum;
            if(delNum>=2) break;
            delIndex = i;
            ++i;
            continue;            
        } else if(s[i]==s[j-1]) {
            ++delNum;
            if(delNum>=2) break;
            delIndex = j;
            --j;
            continue;            
        } else {
            return -1;
        }
    }
    
    if(delNum==1) return delIndex;
    return -1;
}

#else

bool palindromeIndex(const string &s, int i, int j) {
    while(i<j) {
        if(s[i]!=s[j]) return false;
        ++i;
        --j;
    }

    return true;
}

int palindromeIndex(string s) {
    int i = 0;
    int j = (int)s.size()-1;

    while(i<j) {
        if(s[i]==s[j]) {
            ++i;
            --j;
            continue;
        }

        //Only remove 1 element
        if(palindromeIndex(s, i+1, j)) {
            return i;
        }
        if(palindromeIndex(s, i, j-1)) {
            return j;
        }

        return -1;
    }

    return -1;
}

#endif

int main()
{
    //ofstream fout(getenv("OUTPUT_PATH"));

    string q_temp;
    getline(cin, q_temp);

    int q = stoi(ltrim(rtrim(q_temp)));

    for (int q_itr = 0; q_itr < q; q_itr++) {
        string s;
        getline(cin, s);

        int result = palindromeIndex(s);

        //fout << result << "\n";
        cout << result << endl;
    }

    //fout.close();

    return 0;
}

string ltrim(const string &str) {
    string s(str);

    s.erase(
        s.begin(),
        find_if(s.begin(), s.end(), not1(ptr_fun<int, int>(isspace)))
    );

    return s;
}

string rtrim(const string &str) {
    string s(str);

    s.erase(
        find_if(s.rbegin(), s.rend(), not1(ptr_fun<int, int>(isspace))).base(),
        s.end()
    );

    return s;
}
