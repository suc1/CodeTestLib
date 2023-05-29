/*
第二想到的是区间切分，2个区间如果重叠切分成3个区间. 但是处理区间很麻烦!!!! 时间复杂度: O(nm)

[使用累积方法](https://www.hackerrank.com/challenges/one-month-preparation-kit-crush/forum/comments/1265738)
1. 开一个维数组n
2. 对于每一个(a, b, k) (开始下标, 终止下标, 增加值)
3. n[a] += k, n[b+1] += -k
4. 循环2, 处理下一个(a, b, k)
5. 一步步扫描n求和，出现的最大值即答案

时间复杂度: O(n)
*/

#if 0   //7 timeout
long arrayManipulation(int n, vector<vector<int>> queries) {
    vector<long> v(n, 0);
    
    for(int i=0; i<(int)queries.size(); ++i) {
        for(int j=queries[i][0]-1; j<queries[i][1]; ++j)
            v[j] += queries[i][2];
    }
    
    long ret = v[0];
    for(long i : v) if(ret<i) ret = i;
    
    return ret;
}
#elif 0       //7 Segmentation Fault      //10000000 100000  (n ,m)
long arrayManipulation(int n, vector<vector<int>> queries) {
    long v[n] = {};
    
    for(int i=0; i<(int)queries.size(); ++i) {
        for(int j=queries[i][0]-1; j<queries[i][1]; ++j)
            v[j] += queries[i][2];
    }
    
    long ret = v[0];
    for(long i : v) if(ret<i) ret = i;
    
    return ret;
}
#elif 0  //7 timeout
long arrayManipulation(int n, vector<vector<int>> queries) {
    long* pV = new long[n];
    for(int i=0; i<n; ++i) pV[i] = 0l;
    
    for(int i=0; i<(int)queries.size(); ++i) {
        for(int j=queries[i][0]-1; j<queries[i][1]; ++j)
            pV[j] += queries[i][2];
    }
    
    long ret = pV[0];
    for(int i=1; i<n; ++i) if(ret<pV[i]) ret = pV[i];
    
    delete []pV;
    return ret;
}
#else
long arrayManipulation(int n, vector<vector<int>> queries) {
    long* pV = new long[n+1];       //Why n+1 because of below 1 
    for(int i=0; i<n+1; ++i) pV[i] = 0l;
    
    for(int i=0; i<(int)queries.size(); ++i) {
        pV[ queries[i][0]-1 ] += queries[i][2];
        pV[ queries[i][1]   ] -= queries[i][2]; //below 1
    }
    
    long ret = pV[0];
    long sum = pV[0];
    for(int i=1; i<n; ++i) {
        sum += pV[i];
        if(ret<sum) ret = sum;
    }
    
    delete []pV;
    return ret;
}
#endif