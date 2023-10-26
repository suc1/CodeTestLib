SinglyLinkedListNode* removeDuplicates(SinglyLinkedListNode* llist) {
    if(llist==nullptr) return nullptr;
    
    SinglyLinkedListNode *cur = llist;
    while(cur->next!=nullptr) {
        if(cur->data!=cur->next->data) {
            cur = cur->next;
            continue;
        }
        
        SinglyLinkedListNode* next = cur->next;
        cur->next = cur->next->next;
        delete next;
    }
    
    return llist;
}