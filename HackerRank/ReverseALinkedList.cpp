/*
ReverseADoublyLinkedList.cpp每次只处理一个节点

因为链表一次只处理两个元素，所以天然是两个元素的滑动窗口
剩下是考虑头尾的特殊情况
*/

SinglyLinkedListNode* reverse(SinglyLinkedListNode* llist) {
    SinglyLinkedListNode* p1 = nullptr;
    SinglyLinkedListNode* p2 = llist;
    
    while(p2!=nullptr) {
        SinglyLinkedListNode* tmp = p2->next;
        p2->next = p1;
        p1 = p2;
        p2 = tmp;        
    }
        
    return p1;
}
