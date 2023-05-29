/*
堆(Heap): 一棵完全二叉树的数组对象
runoob/Heap.cpp

索引从0开始，可以得到规律
1. 节点的父节点是 （i-1）/2。
2. 节点的左子节点是 2*i+1，
3. 节点的右子节点是 2*i+2，

堆查找: 只能采用顺序查找
堆删除: 把找到元素和最后元素交换，然后shiftDown()/shiftUp()
*/

#if 0 //8 timeout using vector  //没有用Heap的概念
int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    int q;
    cin >> q;
    vector<int> heap;
    
    for(int i=0; i<q; ++i) {
        int t;
        int v;
                
        cin>>t;
        switch (t) {
            case 1: //add
                cin >> v;
                heap.push_back(v);
                break;
            case 2: //delete
                cin >> v;
                {
                    vector<int>::iterator it;
                    for(it=heap.begin(); it!=heap.end(); ++it) {
                        if(*it == v) {
                            heap.erase(it);
                            break;
                        }
                    }        
                }                
                break;
            case 3: //print
                {
                    int min = heap[0];
                    for(int i=1; i<heap.size(); ++i) {
                        if(min>heap[i]) min=heap[i];
                    }
                    cout<< min << endl;
                }
                break;
        }
    }
    return 0;
}
#elif 0   //10 timeout using list   //没有用Heap的概念
int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    int q;
    cin >> q;
    list<int> heap;
    
    for(int i=0; i<q; ++i) {
        int t;
        int v;
                
        cin>>t;
        switch (t) {
            case 1: //add
                cin >> v;
                heap.push_back(v);
                break;
            case 2: //delete
                cin >> v;
                {
                    list<int>::iterator it;
                    for(it=heap.begin(); it!=heap.end(); ++it) {
                        if(*it == v) {
                            heap.erase(it);
                            break;
                        }
                    }
                }                
                break;
            case 3: //print
                {
                    list<int>::const_iterator it = heap.cbegin();
                    int min = *it;
                    for(; it!=heap.cend(); ++it) {
                        if(min>*it) min=*it;
                    }
                    cout<< min << endl;
                }
                break;
        }
    }
    return 0;
}
#else   //在std::Heap的基础上增加函数
class HeapHelper {
public:
    static int FindHeap(const vector<int>& v, int value) {
        for(int i=0; i<(int)v.size(); ++i) {
            if(v[i]==value) return i;
        }
    
        return -1;
    }

    static bool RemoveHeap(vector<int>& v, int value) {
        int f = FindHeap(v, value);
        if(f<0) return false;
        
        int len = v.size();
        std::swap(v[f], v[len-1]);
        v.pop_back();
        
        ShiftDown(v, f);
        return true;
    }
    
private:    
    static void ShiftDown(vector<int>& v, int k){
        int len = v.size();
        while( 2*k+1 < len ) {
            int i = 2*k+1;
            if( i+1<len && v[i+1]<v[i] ) ++i;

            if( v[k] <= v[i] ) return;
            std::swap(v[k], v[i]);
            k = i;
        }
    }
};

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    int q;
    cin >> q;
    vector<int> heap;
    
    for(int i=0; i<q; ++i) {
        int t;
        int v;
                
        cin>>t;
        switch (t) {
            case 1: //add
                cin >> v;
                heap.push_back(v);
                if(heap.size()>1) std::push_heap(heap.begin(), heap.end(), std::greater<int>());               
                break;
            case 2: //delete
                cin >> v;
                HeapHelper::RemoveHeap(heap, v);           
                break;
            case 3: //print
                //std::make_heap(heap.begin(), heap.end());
                cout << heap[0] << endl;
                break;
        }
    }
    return 0;
}
#endif
