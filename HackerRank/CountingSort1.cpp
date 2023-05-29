vector<int> countingSort(vector<int> arr) {
    //[0, 100)
    vector<int> ret(100, 0);
    for(int i : arr) {
        ++ (ret[i]);
        //ret[i] = ret[i] + 1;
    }
    
    return ret;
}