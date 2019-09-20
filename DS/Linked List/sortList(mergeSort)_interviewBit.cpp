/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
ListNode* getM(ListNode* start,ListNode* end)
{
    ListNode* slow=start;
    ListNode* fast=start->next;
    while(fast!=end&&fast!=end->next)
    {
        slow=slow->next;
        fast=fast->next->next;
    }
    return slow;
}
ListNode* merge(ListNode* st1,ListNode* st2)
{
    ListNode* i1=st1;
    ListNode* i2=st2;
    ListNode* prev=NULL,*p2=NULL,*h=NULL;
    while(i1!=NULL&&i2!=NULL)
    {
        if(i1->val<i2->val)
        {
            if(prev==NULL)
            {
                h=i1;
            }
            prev=i1;
            i1=i1->next;
        }
        else
        {
            if(prev==NULL)
            {   h=i2;
                ListNode* temp=i2->next;
                h->next=i1;
                prev=h;
                i2=temp;
            }
            else
            {
                ListNode* temp=i2->next;
                prev->next=i2;
                i2->next=i1;
                prev=prev->next;
                i2=temp;
            }
        }
    }
    if(i1==NULL)
        prev->next=i2;
    return h;
    
}
ListNode* mergeSort(ListNode *head,ListNode* start,ListNode* end)
{
    if(head==NULL)
        return NULL;
    if(start==end)
        return start;
    ListNode* mid=getM(start,end);
    ListNode* start1=mid->next;
    mid->next=NULL;
    ListNode* st1=mergeSort(head,start,mid);
    ListNode* st2=mergeSort(head,start1,end);
    return merge(st1,st2);
}
ListNode* Solution::sortList(ListNode* A) {
    ListNode*A1=A;
    if(A1==NULL)
        return A1;
    while(A1->next)
    {
        A1=A1->next;
    }
    return mergeSort(A,A,A1);
}
