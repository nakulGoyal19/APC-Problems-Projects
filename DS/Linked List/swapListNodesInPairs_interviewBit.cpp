/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 * 
 * typedef struct ListNode listnode;
 * 
 * listnode* listnode_new(int val) {
 *     listnode* node = (listnode *) malloc(sizeof(listnode));
 *     node->val = val;
 *     node->next = NULL;
 *     return node;
 * }
 */
/**
 * @input A : Head pointer of linked list 
 * 
 * @Output head pointer of list.
 */
listnode* swapPairs(listnode* A) {
    if(A==NULL||A->next==NULL)
        return A;
    listnode* temp;
    listnode* temp2;
    listnode* start;
    
    temp=A;
    A=A->next;
    temp2=A->next;
    A->next=temp;
    temp->next=temp2;
    start=temp;
    temp=temp->next;
    while(temp&&temp->next)
    {
        start->next=temp->next;
        temp2=start->next->next;
        start->next->next=temp;
        temp->next=temp2;
        start=temp;
        temp=temp->next;
    }
    return A;
    
}
