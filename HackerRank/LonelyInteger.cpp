int lonelyinteger(vector<int> a) {
    map<int, int> db;
    for(int i : a) {
        auto it = db.find(i);
        if(it==db.end()) {
            db[i] = 1;
        } else {
            it->second = it->second + 1;
        }
    }
    
    for(auto it=db.begin(); it!=db.end(); ++it) {
        if(it->second==1) return it->first;
    }
    
    return 0;   //not found
}