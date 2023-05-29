/*
堆(Heap): 一棵完全二叉树的数组对象
https://www.runoob.com/data-structures/heap-storage.html

一个典型场景: 每次取最大值
1. 不做特殊处理:
1.1 增加新值，O(1)
1.2 寻找最大值, O(n)
1.3 取走最大值, O(n)
2. 使用Heap
2.1 增加新值，O(ln),        push_heap()
2.2 寻找最大值, O(1)        vector[0]
2.3 取走最大值, O(ln)       pop_heap()


满足下列性质：
1. 堆中某个节点的值总是不大于或不小于其父节点的值。(是一种弱排序，但不是严格意义上的排序。同样一组数据，执行顺序不同，结果树也不同)
2. 堆总是一棵完全二叉树。

时间复杂度在 O(1)~O(logn)

假设当前元素的索引位置为 i，(从1开始)，可以得到规律：
1. parent(i) = i/2（取整）
2. left child(i) = 2*i
3. right child(i) = 2*i +1

索引从0开始，可以得到规律
1. 节点的父节点是 （i-1）/2。
2. 节点的左子节点是 2*i+1，
3. 节点的右子节点是 2*i+2，

C++/algorithm/heap: 基本思想:在容器基础上调整元素顺序, 不做增删元素工作
make_heap()
push_heap(), pop_heap(): 只是调整容器里面元素的顺序
取最大值 v.front()
push_heap() 把新值放在容器最后, 所以需要先在v.push_back()
pop_heap()  最大值放在最后，所以需要v.pop_back()

sort_heap() 严格排序
is_heap_until() 找到不是Heap的第一个元素
*/
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

template<class T>
class MaxHeap
{
private:
    vector<T>   m_data;
    //int         m_count;
    //int         m_capacity;

public:
    MaxHeap(int capacity) {
        m_data.reserve( capacity+1 );
        m_data.push_back(1234);     //[0] is garbage
    }

    int size(){
        return m_data.size()-1;
    }

    bool isEmpty(){
        return size() == 0;
    }
    
    ////堆的 shift up
    void insert(T item){
        m_data.push_back(item);
        shiftUp( size() );
    }

    void Debug() {
        for(int i=1; i<m_data.size(); ++i) cout << m_data[i] << '\t';
        cout << endl;
    }

    ////堆的 shift down
    //获取最大堆中的堆顶元素
    T getMax(){
        return m_data[1];
    }

    // 从最大堆中取出堆顶元素, 即堆中所存储的最大数据
    T extractMax(){
        T ret = m_data[1];
        swap( 1 , size() ); //将数组最后一位数组放到根节点
        m_data.pop_back();

        shiftDown(1);
        return ret;
    }
private:
    ////堆的 shift up
    // 交换堆中索引为i和j的两个元素
    void swap(int i, int j){
        std::swap(m_data[i], m_data[j]);
    }

    void shiftUp(int k){
        while( k > 1 && m_data[k/2]<m_data[k] ){
            swap(k, k/2);
            k /= 2;
        }
    }

    //堆的 shift down
    void shiftDown(int k){
        int count = size();
        while( 2*k <= count ) { //有孩子?
            int j = 2*k; // 在此轮循环中, m_data[k]和m_data[j]交换位置
            if( j+1 <= count && m_data[j+1] > m_data[j] ) ++j;

            // data[j] 是两个孩子的中的最大值
            if( m_data[k] >= m_data[j] ) break;
            swap(k, j);
            k = j;
        }
    }
};

#if 0
int main() {
    MaxHeap<int> maxHeap(100);
    int example[] = {62, 41, 30, 28, 16, 22, 13, 19, 17, 15, 52};
    for(int i=0; i<sizeof(example)/sizeof(example[0]); ++i) maxHeap.insert(example[i]);
    maxHeap.Debug();

    cout << "max=" << maxHeap.extractMax() << endl;
    maxHeap.Debug();

    // 将最大堆中的数据逐渐使用extractMax取出来, 取出来的顺序应该是按照从大到小
    int len = maxHeap.size();
    for(int i=0; i<len; ++i) cout << maxHeap.extractMax() << ',';
    cout << endl;
}
#else
void DebugVector(const char* ex, const vector<int>& v) {
    cout << ex;
    for(int i=0; i<v.size(); ++i) cout << v[i] << '\t';     //使用了0元素
    cout << endl;
}
int main0() {
    int example[] = {62, 41, 30, 28, 16, 22, 13, 19, 17, 15};
    //vector<int> maxHeap( example.begin(), example.end() );        //error: non-class type
    vector<int> maxHeap( example, example+10);                    //ok
    //vector<int> maxHeap = {62, 41, 30, 28, 16, 22, 13, 19, 17, 15}; //ok in C++11

    return 0;
}

int main () {
  int myints[] = {10,20,30,5,15};
  std::vector<int> v(myints,myints+5);
  DebugVector("orign: ", v);

  std::make_heap (v.begin(),v.end());
  DebugVector("make_heap: ", v);
  
  std::pop_heap (v.begin(),v.end());
  DebugVector("pop_heap: ", v);
  v.pop_back();
  DebugVector("v.pop_back(): ", v);
  
  v.push_back(99); 
  std::push_heap (v.begin(),v.end());
  DebugVector("v.push_back(): ", v);

  std::sort_heap (v.begin(),v.end());
  DebugVector("v.sort_heap(): ", v);

  return 0;
}
#endif