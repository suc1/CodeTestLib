/*
//Truck Tour
https://www.hackerrank.com/test/3em71ltlfrk/questions/6sqmn1811gk

无法使用滑动窗口来解决，因为任何一站都可能没油不能动
*/
#include <bits/stdc++.h>

using namespace std;

string ltrim(const string &);
string rtrim(const string &);
vector<string> split(const string &);



/*
 * Complete the 'truckTour' function below.
 *
 * The function is expected to return an INTEGER.
 * The function accepts 2D_INTEGER_ARRAY petrolpumps as parameter.
 */
#if 0
void Debug(const vector<vector<int>> &petrolpumps) {
    for(int i=0; i<(int)petrolpumps.size(); ++i) {
        cout << i << endl;
        for(int j=0; j<(int)petrolpumps[i].size(); ++j) {
            cout << petrolpumps[i][j] << ',';
        }
        cout << endl;
    }
}

int truckTour(vector<vector<int>> petrolpumps) {
    int sum;
    int startPoint = 0;
    int len = (int)petrolpumps.size();
    
    while(startPoint < len) {
        sum = 0;
        for(int i=0; i<len; ++i) {
            int ii = (startPoint+i) % len;      //circle
            sum += petrolpumps[ii][0] - petrolpumps[ii][1];
            if(sum<0) {
                ++startPoint;
                break;
            }
        }
            
        if(sum>0)   // I think `if(sum>=0)` is ok, but test case fail
        {
            return startPoint;
        }
    }
    
    return -1;
}

#else
int truckTour(vector<vector<int>> petrolpumps) {
    int len = petrolpumps.size();
    
    for(int i=0; i<len; ++i) {
        int sum = 0;
        for(int j=0; j<len; ++j) {
            int start = (i+j) % len;
            sum += petrolpumps[start][0] - petrolpumps[start][1];
            if(sum<0) {
                break;
            } 
        }
        if(sum>=0) return i;
    }
    
    return -1;
}
#endif