listnode* partition(listnode* A, int B) {
    if(!A)
        return A;
    if(A->val>=B)
    {
        int c=0;
        listnode* temp=A;
        listnode* thead;
        while(temp->next!=NULL)
        {
            
            if(temp->next->val<B)
            {
               if(c==0)
               {
                   listnode* ptr=temp->next;
                   temp->next=temp->next->next;
                   ptr->next=A;
                   A=ptr;
                   c=1;
                   thead=A;
               }
               else
               {
                   listnode* ptr=temp->next;
                   temp->next=temp->next->next;
                   ptr->next=thead->next;
                   thead->next=ptr;
                   thead=thead->next;
               }
            }
            else
                temp=temp->next;
        }
        return A;
    }
    else
    {
        listnode* temp=A;
        while(temp->next!=NULL&&temp->next->val<B)
        {
            temp=temp->next;
        }
        if(temp->next==NULL)
            return A;
        listnode* thead=temp;
        while(temp->next!=NULL)
        {
            if(temp->next->val<B)
            {
                listnode* ptr=temp->next;
                temp->next=temp->next->next;
                ptr->next=thead->next;
                thead->next=ptr;
                thead=thead->next;
            }
            else
                temp=temp->next;
        }
        return A;
    }
    return A;
}

//OR

/*ListNode *partition(ListNode *head, int x) {

    if (!head) return NULL;
    ListNode * iterator = head; 

    ListNode * start = new ListNode(0); // list of nodes greater than x
    ListNode * tail = start;

    ListNode * newHead = new ListNode(0); 
       newHead -> next = head;
    ListNode * pre = newHead; // previous node, we need it for removing


    while (iterator) {
        if (iterator -> val >= x) {
            pre -> next = iterator -> next; // remove from our list
            tail -> next = iterator; // add to list of nodes greater than x
            tail = tail -> next;
            iterator = iterator -> next;
            tail -> next = NULL;
        }
        else
            pre = iterator, iterator = iterator -> next;
    }
    pre -> next = start -> next;
    return newHead -> next;
}
*/

