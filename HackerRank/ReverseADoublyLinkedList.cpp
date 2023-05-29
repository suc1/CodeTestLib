/*
前后指针交换即可, 只处理一个节点
只有在处理头尾出现困难，才考虑新增头尾节点
*/

#if 0
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