/*
优化堆排序 : 使用原地堆排序

基础堆排序开辟了额外的空间进行构造堆和对堆进行排序???   没有开新空间!!! 指通过extractMax()排序
虽然代码确实生成一个新数组，但这是代码编写的问题，而不是算法的问题

C++/algorithm/heap:使用了原地的做法-使用外部容器

1. 对于一个最大堆，首先将开始位置数据和数组末尾数值进行交换，那么数组末尾就是最大元素
2. 再对少最后一个元素进行 shift down 操作，重新生成最大堆
3. 将新生成的最大数和整个数组倒数第二位置进行交换
4. 以此类推
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

    ////原地堆排序
    /*
    public static void sort(Comparable[] arr) {

        int n = arr.length;

        // 注意，此时我们的堆是从0开始索引的
        // 从(最后一个元素的索引-1)/2开始
        // 最后一个元素的索引 = n-1
        for (int i = (n - 1 - 1) / 2; i >= 0; i--)
            shiftDown(arr, n, i);
       
        for (int i = n - 1; i > 0; i--) {
            swap(arr, 0, i);
            shiftDown(arr, i, 0);
        }
    }
    */

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