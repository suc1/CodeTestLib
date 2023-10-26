void PrintVector(const char* explain, const vector<int>& a) {
    cout << explain;
    for(auto i : a) {
        cout << i << ',';
    }
    cout << endl;
}

vector<int> GetPrime(int q) {
    vector<int> ret = {2,3,5,7};
    q -= ret.size();
    int start = 7+1;
    
    while(q>0) {
        bool prime = true;
        for(int i: ret) {
            if(start%i==0) {
                prime = false;
                break;
            }
        }
        
        if(prime) {
            ret.push_back(start);
            start += 2;
            --q;
        } else ++start;
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
