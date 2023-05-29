int sockMerchant(int n, vector<int> ar) {
    map<int, int> db;
    for(auto it : ar) {
        auto f = db.find(it);
        
        if(f==db.end()) {
            db[ it ] = 1;
        } else {
            ++( db[it] );
        }
    }
    
    int sum = 0;
    for(auto it : db) {
        sum += it.second/2;
    }
    
    return sum;
}