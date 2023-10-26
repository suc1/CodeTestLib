/*
前后指针交换即可, 只处理当前一个节点 (另一个思想: 使用窗口思想, 两个节点)
只有在处理头尾出现困难，才考虑新增头尾节点
*/

#if 0   //只处理当前一个节点
DoublyLinkedListNode* reverse(DoublyLinkedListNode* llist) {
    DoublyLinkedListNode* cur    = llist;
    DoublyLinkedListNode* oldCur = llist;
    
    while(cur!=nullptr) {
        std::swap(cur->next, cur->prev);
        oldCur = cur;
        cur = cur->prev;
    }

    return oldCur;
}
#elif 0 //使用窗口思想, 两个节点
DoublyLinkedListNode* reverse(DoublyLinkedListNode* llist) {
    DoublyLinkedListNode *p1=nullptr, *p2=llist;
    while(p2!=nullptr) {
        DoublyLinkedListNode * p3=p2->next;
        p2->next=p1;
        p2->prev=p3;
        
        p1=p2;
        p2=p3;
    }
    
    return p1;
}
#else
//少定义一个变量
DoublyLinkedListNode* reverse(DoublyLinkedListNode* llist) {
    DoublyLinkedListNode* oldCur = llist;
    
    while(llist!=nullptr) {
        std::swap(llist->next, llist->prev);
        oldCur = llist;
        llist = llist->prev;
    }

    return oldCur;
}
#endif