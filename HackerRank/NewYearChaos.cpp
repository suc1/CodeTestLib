/*
https://www.hackerrank.com/challenges/one-week-preparation-kit-new-year-chaos/problem?isFullScreen=true&h_l=interview&playlist_slugs%5B%5D=preparation-kits&playlist_slugs%5B%5D=one-week-preparation-kit&playlist_slugs%5B%5D=one-week-day-four

//滑动窗口法
https://www.cnblogs.com/huansky/p/13488234.html

难点:怎么想到解决方法是滑动窗口????
两层循环，复杂度O(n*n)

降低路径: 
一个选择是O(n*ln(n))，一个循环改成取半, 二分法排序
另一个选择O(n)，滑动窗口
最好选择是O(1), Hash


因为最多只能行贿2人，所以窗口宽度是3: [P1, P2, P3].
例如[1,2,3], 如果1跑出窗口，则"Too chaotic". 2&3靠滑动窗口解决???

!!!按当前位置是P1, P2或者P3分类!!!

每个位置如果合理有三个选项:(以位置1举例, [1,2,3])
位置1是1: 滑动窗口, 下一步考察[2,3,4], 即P1=P2; P2=P3; ++P3;  //0行贿
位置1是2: 滑动窗口, 下一步考察[1,3,4], 即P1不变; P2=P3; ++P3  //+1行贿
位置1是3: 滑动窗口, 下一步考察[1,2,4], 即P1不变; P2不变; ++P3  //+2行贿
*/
#include <bits/stdc++.h>

using namespace std;

string ltrim(const string &);
string rtrim(const string &);
vector<string> split(const string &);

/*
 * Complete the 'minimumBribes' function below.
 *
 * The function accepts INTEGER_ARRAY q as parameter.
 */

#if 0   //4 timeout
void minimumBribes(vector<int> q) {
    int len = (int) q.size();
    int count[ len ];
    for(int i=0; i<len; ++i) count[i] = 0;
    
    for(int i=0; i<len-1; ++i) {
        for(int j=i+1; j<len; ++j) {
            if(q[i]>q[j]) {
                int temp = q[i];
                q[i] = q[j];
                q[j] = temp;
                --temp; //start from 0
                count[temp] = count[temp] + 1;
                if(count[temp] >2) {
                    cout << "Too chaotic" << endl;
                    return;
                } 
            }
        }
    }
    
    int sum = 0;
    for(int j : count) {
        sum+=j;
    }
    cout << sum << endl;
}

#else

void minimumBribes(vector<int> q) {
    int p1=1, p2=2, p3=3;
    int sum = 0;
    
    for(int i=0; i<q.size(); ++i) {
        if(q[i]==p1) {
            p1=p2;
            p2=p3;
            ++p3;
        } else if(q[i]==p2) {
            p2=p3;
            ++p3;
            ++sum;
        } else if(q[i]==p3) {
            ++p3;
            sum+=2;
        } else {
            cout << "Too chaotic" << endl;
            return;
        }
    }
    cout << sum << endl;
}

#endif

int main()
{
    string t_temp;
    getline(cin, t_temp);

    int t = stoi(ltrim(rtrim(t_temp)));

    for (int t_itr = 0; t_itr < t; t_itr++) {
        string n_temp;
        getline(cin, n_temp);

        int n = stoi(ltrim(rtrim(n_temp)));

        string q_temp_temp;
        getline(cin, q_temp_temp);

        vector<string> q_temp = split(rtrim(q_temp_temp));

        vector<int> q(n);

        for (int i = 0; i < n; i++) {
            int q_item = stoi(q_temp[i]);

            q[i] = q_item;
        }

        minimumBribes(q);
    }

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

vector<string> split(const string &str) {
    vector<string> tokens;

    string::size_type start = 0;
    string::size_type end = 0;

    while ((end = str.find(" ", start)) != string::npos) {
        tokens.push_back(str.substr(start, end - start));

        start = end + 1;
    }

    tokens.push_back(str.substr(start));

    return tokens;
}
