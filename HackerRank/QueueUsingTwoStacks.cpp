/*
que.top() 得判栈为空
*/

#include <stack>
using namespace std;

void MoveTail2Head(stack<int>& head, stack<int>& tail) {
    if(head.empty()) {
        while(!tail.empty()) {
            head.push( tail.top() );
            tail.pop();
        }
    }
}

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    std::stack<int> head;
    std::stack<int> tail;
    
    int q;
    cin >> q;
    for(int i=0; i<q; ++i) {
        int t, x;
        cin >> t;
        //cout << '=' << t << ',';
        switch(t) {
            case 1: //enqueue
                cin>>x;
                tail.push(x);
                //cout << x << endl;
                break;
            case 2: //dequeue
                MoveTail2Head(head, tail);
                head.pop();
                //cout << endl;
                break;
            case 3: //print top()
                MoveTail2Head(head, tail);
                //cout << endl;
                cout << head.top() << endl;
                break;
        }        
    }
       
    return 0;
}
