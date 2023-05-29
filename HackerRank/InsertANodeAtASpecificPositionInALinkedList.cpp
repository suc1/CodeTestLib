/*
后插入
*/
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