/*最终思路:
1. 先考虑一行的所有种类数:
m=1: 第一块砖是一种情况:1
m=2: 第一块砖有两种情况:1,2, 共2种情况 
m=3: 第一块砖有三种情况:1,2,3, 共m2+m1+1=2+1+1=4种情况
m=4: 第一块砖有四种情况:1,2,3,4, 共m3+m2+m1+1=4+2+1+1=8种情况
m=5: 第一块砖有四种情况:1,2,3,4, 共m4+m3+m2+m1=8+4+2+1=15种情况

所以通式是
P(m) = P(m-1) + P(m-2) + P(m-3) + P(m-4)
p1=1; p2=2; p3=4; p4=8; p5=15

2. n层砖所有种类数: D(n, m) = P(m) ^ n, 包含好G(n,m)坏B(n,m)的垒法
G(n,m) + B(n,m) = P(m) ^ n,
**关键: 好坏必须单独定义, 方便思考**

3. 考虑有一块贯通的竖缝坏B(n,m)的垒法, 左右两边都是好的垒法:
设第1块砖有一块贯通的缝，G(n,1) * G(n, m-1),
设第2块砖有一块贯通的缝，G(n,2) * G(n, m-2),
...
设第m-1块砖有一块贯通的缝，G(n,m-1) * G(n, 1),

所以通式是
B(n,m) = G(n,1) * G(n, m-1) + G(n,2) * G(n, m-2) + ... + G(n,m-1) * G(n, 1)

4. 所以，好垒法:
G(n,m) = P(m)^n - B(n,m) = P(m)^n - SUM[1<=i<=m-1][G(n, i) * G(n, m-i)]
G(n,1) = 1
G(n,2) = P(2)^n - G(n,1) * p(1)^n

5. 算式里面有许多重复计算, G(n,m), P(m)
*/

/* 第一次思路: 组合数学的分类法
使用图形考虑太难，所以首先尝试数理方法-组合数学: 正确地分类!!!
高 n 宽 m 的墙, 不考虑砖竖立情况,因为是lego!!!
一行一行考虑,因为是lego!!!
创建好布局是S(n,m)，是避免贯穿竖线左边重复贯穿竖线的关键点!!!

https://www.hackerrank.com/challenges/one-week-preparation-kit-lego-blocks/forum/comments/1098199
解释了思考方法

https://www.hackerrank.com/challenges/one-week-preparation-kit-lego-blocks/forum/comments/1174845
列出最终式子

https://stackoverflow.com/questions/9009139/optimising-multiplication-modulo-a-small-prime
`a * b mod p = ((a-p)*(b-p))%p`

二项式定理，又称牛顿二项式定理，
(a+b)^n = C(n,0)a^n + C(n,1)a^(n-1)b + ... + C(n,i)a^(n-i)b^i + ... + C(n,n)b^n
C(n,i) = n!/(n-i)!i!

https://www.hackerrank.com/challenges/one-week-preparation-kit-lego-blocks/forum/comments/1275344
使用此python查测试错误，overflow

1. 总排列数: p(m)^n
p(1) = 2^(1-1) = 1
p(2) = 2^(2-1) = 2
p(3) = 2^(3-1) = 4
p(4) = 2^(4-1) = 8
//第一块砖是    1，      2，      3，      4
p(5) =       p(4) +   p(3) +   p(2) +   p(1) = 15
p(6)                                         = 29
...
p(m) =     p(m-1) + p(m-2) +  p(m-3) +  p(m-4)

2. 不良布局的数量: D(n,m); 好布局是S(n,m),  S(n,m) = p(m)^n - D(n,m)
考虑一堵高 n、宽 m 的墙，在最左边的位置有一条从上到下的直线（即每一行最左边的方块的长度都是 1）。 满足此条件的不良布局数量为 S(n,1) * P(m-1)^n，
因为在该行的左侧有 S(n,1) 个好布局（没有不良布局 m = 1)，在它的右边我们有 P(m-1)^n 布局（好 + 坏）。 

我们可以将线向右移动一步，找出在左侧第二个位置有一条线的不良布局的数量，同时排除我们已经计算过的所有不良布局。 那等于 S(n,2) * P(m-2)^n。 
这是因为，在该行的左侧，我们计算了所有好的布局，以确保我们没有重新计算该行位于先前位置时坏的布局。在线的右边，我们只是计算所有可能的布局。

我以前没有设置S(n,m)，所以理解错误(!!!!但是这实际有重复，左侧里面可能有垂直线!!!!)

我们继续然后向右移动线并计算不良布局，这将在最后产生 D(n,m) = S(n,1)*P(m-1)^n + S(n,2)*P(m-2)^n + ... + S(n,m-1)*P(1)^n。 
因此，合理布局 S(n,m) = p(m)^n - D(n,m) = P(m)^n - sum{ [i=1, m-1] [ S(n,i) * p(m-i)^n] }

s(n, 1) = 1
s(n, 2) = P(2)^n - S(n,1) * p(1)^n = 2^n - 1
s(n, 3) = P(3)^n - S(n,1) * p(2)^n - S(n,2) * p(1)^n = 4^n - 2^n - (2^n-1) = (2^n-1)^2
s(n, 4) = P(4)^n - S(n,1) * p(3)^n - S(n,2) * P(2)^n - S(n,3) * P(1)^n = (2^n-1)^3
*/

#include <bits/stdc++.h>

using namespace std;

string ltrim(const string &);
string rtrim(const string &);
vector<string> split(const string &);

/*
 * Complete the 'legoBlocks' function below.
 *
 * The function is expected to return an INTEGER.
 * The function accepts following parameters:
 *  1. INTEGER n
 *  2. INTEGER m
 */

const long mod = 1000000000 + 7;
long power(int m, int n) {
    unsigned long sum =m;
    for(int i=1; i<n; ++i) {
        sum *= m;
        sum %= mod; //overflow n=8, m=10, goodlayout=634597424
    }
    return sum;
}
int legoBlocks(int n, int m) {
    long p[m];
    if(m>=1) p[0]=1;
    if(m>=2) p[1]=2;
    if(m>=3) p[2]=4;
    if(m>=4) p[3]=8;
    
    for(int i=4; i<m; ++i) {
        p[i] = p[i-1] + p[i-2] + p[i-3] + p[i-4];
        p[i] = p[i] % mod; //overflow n=529 m=190  goodlayout=461438538
    }
        
    long pn[m];  //p(m)^n
    for(int i=0; i<m; ++i) {
        pn[i] = power(p[i], n) % mod;   
    } 
    
    //trouble: start from 1 VS start from 0
    long s[m];      //S(n,m) = p(m)^n - sum{ [i=1, m-1] [ S(n,i) * p(m-i)^n] }
    for(int i=0; i<m; ++i) {
        s[i] = pn[i];
        for(int j=0; j<i; ++j) {
            long tmp = (s[j] * pn[i-j-1]) % mod;
            s[i] = s[i] - tmp;
            s[i] += mod;    //avoid negative!!!
            s[i] = s[i] % mod;
        }
    }
    
    
    cout << "p=";
    for(int i=0; i<m; ++i) cout << p[i] << ',';
    cout << endl;
    
    cout << "pn=";
    for(int i=0; i<m; ++i) cout << pn[i] << ',';
    cout << endl;
    
    cout << "s=";
    for(int i=0; i<m; ++i) cout << s[i] << ',';
    cout << endl;
    
    //n=8 m=10  goodlayout = 634597424
    return (int)s[m-1];
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string t_temp;
    getline(cin, t_temp);

    int t = stoi(ltrim(rtrim(t_temp)));

    for (int t_itr = 0; t_itr < t; t_itr++) {
        string first_multiple_input_temp;
        getline(cin, first_multiple_input_temp);

        vector<string> first_multiple_input = split(rtrim(first_multiple_input_temp));

        int n = stoi(first_multiple_input[0]);

        int m = stoi(first_multiple_input[1]);

        int result = legoBlocks(n, m);

        fout << result << "\n";
    }

    fout.close();

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
