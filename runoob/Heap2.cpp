/*
C++/algorithm/heap: 基本思想:在容器基础上调整元素顺序, 不做增删元素工作

[基础堆排序](https://www.runoob.com/data-structures/heap-sort.html)
std::make_heap()使用此算法？？
shiftUp()逐个插入到堆中，算法的时候时间复杂度是 O(nlogn)

Heapify，算法时间复杂度为 O(n)
基本思想:
1. 从最底层非叶的父节点开始，对每个分支shiftDown()
2. 向上一层，对每个分支（一层）shiftDown()
3. 直到到达根
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

    ////heapify进行堆排序       //开辟了额外的空间
    void Heapify(T arr[], int n){
        for(int i=0; i<n; ++i) m_data.push_back( arr[i] );
        //从第一个不是叶子节点的元素开始
        for( int i = n/2 ; i >= 1 ; --i)
            shiftDown(i);
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

void DebugVector(const char* ex, const vector<int>& v) {
    cout << ex;
    for(int i=0; i<v.size(); ++i) cout << v[i] << '\t';     //使用了0元素
    cout << endl;
}
int main() {
    int arr[] = {15, 17, 19, 13, 22, 16, 28, 30, 41, 62}; //ok in C++11
    MaxHeap<int> maxHeap(10);
    maxHeap.Heapify(arr, 10);
    maxHeap.Debug();

    return 0;
}
