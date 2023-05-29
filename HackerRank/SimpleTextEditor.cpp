/*
可以连续两次undo
*/
int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    int q;
    cin >> q;
    
    string str;
    stack<string> undo; //for undo
    for(int i=0; i<q; ++i) {
        int t;
        cin >> t;
        //cout << "deb=" << i << " t=" << t << ',' << str << endl;
        
        string w;
        int k;
        switch(t) {
            case 1: //append
                cin >> w;
                undo.push( str );
                str += w;
                break;
            case 2: //delete
                cin >> k;
                undo.push( str );
                str.erase( str.size()-k, k);
                break;
            case 3: //print
                cin >> k;
                cout << str[k-1] << endl;
                break;
            case 4: //undo
                str = undo.top();
                undo.pop();
                break;  
        }               
    }
    return 0;
}
