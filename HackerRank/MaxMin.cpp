/*
K个数字是任选，可以考虑排序
数字不唯一: 有助减少不公，所以排序没问题
*/
int maxMin(int k, vector<int> arr) {
    std::sort(arr.begin(), arr.end());
    
    int ret = arr[k-1]-arr[0];

    for(int i=1; i<=arr.size()-k; ++i) {
        int tmp = arr[i+k-1] - arr[i];
        if(tmp<ret) ret = tmp;
    }
    
    return ret;
}