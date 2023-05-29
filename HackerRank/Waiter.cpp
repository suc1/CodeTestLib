void PrintVector(const char* explain, const vector<int>& a) {
    cout << explain;
    for(auto i : a) {
        cout << i << ',';
    }
    cout << endl;
}

vector<int> GetPrime(int q) {
    vector<int> ret;
    
    ret.push_back(2);       //q=1, How many prime should be calculated
    if(q>=2) ret.push_back(3);
    if(q>=3) ret.push_back(5);
    
    int i = 7;
    while(ret.size()<q) {
        bool isPrime = true;
        for(int j=0; j<ret.size(); ++j) {
            if(i % ret[j]==0) {
                isPrime = false;
                break;
            }
        }
        if(isPrime) ret.push_back(i);
        ++i;
    }
        
    return ret;
}

vector<int> waiter(vector<int> number, int q) {
    stack<int> A0, A1, B0;
    vector<int> answer;
    for(auto i : number) A0.push(i);
    vector<int> prime = GetPrime(q);
    //PrintVector("Prime=", prime);
    
    stack<int> *pA0 = &A0;
    stack<int> *pA1 = &A1;
    for(int i=0; i<q; ++i) {
        cout << i << endl;
        while(!pA0->empty()) {
            int tmp = pA0->top();
            if(tmp%prime[i]==0) B0.push(tmp);
            else pA1->push(tmp);
            pA0->pop();
        }
        
        while(!B0.empty()) {
            answer.push_back( B0.top() );
            B0.pop();
        }
        
        std::swap(pA0, pA1);
    }
    
    while(!pA0->empty()) {
        answer.push_back( pA0->top() );
        pA0->pop();
    }
    
    return answer;
}
