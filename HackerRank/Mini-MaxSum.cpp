    long sum = 0;
    for(int i : arr) {
        sum += i;
    }
    
    long min = sum - arr[0];
    long max = min;
    
    for(size_t i=1; i<arr.size(); ++i) {
        long tmp = sum-arr[i];
        min = std::min(min, tmp);
        max = std::max(max, tmp);
    }
    cout << min << ' ' << max << endl;
}
