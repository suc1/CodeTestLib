bool has_cycle(SinglyLinkedListNode* head) {
    if(head==nullptr) return false; //????
    
    SinglyLinkedListNode *fast = head;
    do {
        fast = fast ->next;
        if(fast==nullptr) return false;
        fast = fast ->next;
        
        head=head->next;    //slow
        
        if(head==fast) return true;
    } while(fast!=nullptr && head!=nullptr);
    
    return false;
}