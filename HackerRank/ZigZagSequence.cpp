/*
后半截得反序。最后一个除外

奇数才有中间数:  int mid = n/2;     //No (n+1)/2
队列反序: 按奇偶分类很烦，定义左右指针最好, while(left<right) {}
*/

void findZigZagSequence(vector < int > a, int n){
    sort(a.begin(), a.end());
    int mid = n/2;
    swap(a[mid], a[n-1]);

    int st = mid + 1;
    int ed = n - 2;
    while(st <= ed){
        swap(a[st], a[ed]);
        st = st + 1;
        ed = ed - 1;
    }
    for(int i = 0; i < n; i++){
        if(i > 0) cout << " ";
        cout << a[i];
    }
    cout << endl;
}