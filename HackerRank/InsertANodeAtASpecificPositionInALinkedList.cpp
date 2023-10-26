/*
序号从0开始，是前插入。需要考虑在插在头指针的特殊情况
序号从1开始，是后插入, 简单多了

从例子看出，序号从1开始，是后插入
*/
#if 0
SinglyLinkedListNode* insertNodeAtPosition(SinglyLinkedListNode* llist, int data, int position) {
    //ToDo: if(llist==nullptr)
    SinglyLinkedListNode* head = llist;
    
    for(int i=1; i<position; ++i) {
        if(llist==nullptr) return head;
        llist = llist->next;
    }
    
    SinglyLinkedListNode* newNode = new SinglyLinkedListNode(data);
    newNode->next = llist->next;
    llist->next = newNode;
    
    return head;
}
#else   //More strong
SinglyLinkedListNode* insertNodeAtPosition(SinglyLinkedListNode* llist, int data, int position) {
    SinglyLinkedListNode *cur=llist;
    for(int i=1; i<position; ++i) {
        if(cur->next==nullptr) {
            cur->next=new SinglyLinkedListNode(data);
            cur->next->next = nullptr;
            return llist;
        }
        cur = cur->next;
    }
    
    SinglyLinkedListNode *tail = cur->next;
    cur->next = new SinglyLinkedListNode(data);
    cur->next->next = tail;
    
    return llist;
}
#endif
