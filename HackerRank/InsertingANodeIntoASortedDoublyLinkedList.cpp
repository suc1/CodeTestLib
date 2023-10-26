DoublyLinkedListNode* sortedInsert(DoublyLinkedListNode* llist, int data) {
    DoublyLinkedListNode *insert = new DoublyLinkedListNode(data);
    if(data <= llist->data) {
        insert->prev = nullptr;
        insert->next = llist;
        
        llist->prev = insert;
        return insert;
    }
    
    DoublyLinkedListNode *cur = llist;
    while(cur->next!=nullptr) {
        if(cur->data<data) cur = cur->next;
        else break; //forgot this line cause timeout
    }
    
    if(cur->data>data) { //Not tail, in the middle
        cur = cur->prev;
    }
    
    insert->prev = cur;
    insert->next =cur->next;   
        
    cur->next = insert;
    
    return llist;    
}
