#if 0  //merge all duplicate
void AppendNewNode(SinglyLinkedList& newList, int data) {
    if(newList.tail==nullptr) newList.insert_node(data);
    else {
        if(newList.tail->data<data) newList.insert_node(data);
        else if(newList.tail->data>data) assert(!"wrong order");
    }
}
#else
void AppendNewNode(SinglyLinkedList& newList, int data) {
    newList.insert_node(data);    
}

#endif

#if 0       //Slow, need more memory, should delete head1 & head2
SinglyLinkedListNode* mergeLists(SinglyLinkedListNode* head1, SinglyLinkedListNode* head2) {
    SinglyLinkedList newList;
    
    while(head1!=nullptr && head2!=nullptr) {
        if(head1->data == head2->data) {
            AppendNewNode(newList, head1->data);
            AppendNewNode(newList, head1->data); //do not delete duplate
            head1 = head1->next;
            head2 = head2->next;                
        } else if(head1->data < head2->data) {
            AppendNewNode(newList, head1->data);
            head1 = head1->next;
        } else {
            AppendNewNode(newList, head2->data);
            head2 = head2->next;
        }
    }
    
    SinglyLinkedListNode* left = nullptr;
    if(head1!=nullptr) left = head1;
    else if(head2!=nullptr) left = head2;
        
    while(left!=nullptr) {
        AppendNewNode(newList, left->data);
        left = left->next;
    }
    
    return newList.head;
}
#else   //fast, no duplicate
SinglyLinkedListNode* mergeLists(SinglyLinkedListNode* head1, SinglyLinkedListNode* head2) {
    if(head1==nullptr) return head2;
    if(head2==nullptr) return head1;
    
    SinglyLinkedListNode *head;
    if(head1->data<=head2->data) {
        head = head1;
        head1 = head1->next;
    } else {
        head = head2;
        head2 = head2->next;
    }

    SinglyLinkedListNode *cur = head;
    while(head1!=nullptr && head2!=nullptr) {
        if(head1->data<=head2->data) {
            cur->next = head1;
            cur = head1;
            head1 = head1->next;
        } else {
            cur->next = head2;
            cur = head2;
            head2 = head2->next;
        }
    }
    
    if(head1!=nullptr) cur->next=head1;
    else if(head2!=nullptr) cur->next=head2;
    
    return head;
}
#endif