class Solution {
public:
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        ListNode* t1= list1;
        ListNode* t2= list2;
        ListNode* dnode= new ListNode(-1);
        ListNode* temp= dnode;

        while(t1!=nullptr && t2!=nullptr) {
            if(t1->val <t2->val ) {
                temp->next= t1;
                temp=temp->next;
                t1=t1->next;
            } else {
                temp->next=t2;
                temp=temp->next;
                t2=t2->next;
            }
        }

        if(t1) temp->next=t1;
        else temp->next= t2;

        return dnode->next;
    }
};