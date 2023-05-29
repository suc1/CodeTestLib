vector<int> matchingStrings(vector<string> strings, vector<string> queries) {
    map<string, int> db;
    for(auto it : strings) {
        auto find = db.find(it);
        if(find==db.end()) {
            db[it] = 1;
        } else {
            db[it] = find->second + 1;
        }
    }
    
    vector<int> ret;
    for(auto it : queries) {
        auto find = db.find(it);
        if(find==db.end()) {
            ret.push_back(0);
        } else {
            ret.push_back( find->second );
        }
    }
    
    return ret;
}