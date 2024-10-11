class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {

        if(!head || head->next==NULL) return NULL;
        ListNode* temp= head;
        int count=0;
        while(temp!=NULL) {
            count++;
            temp=temp->next;
        }

        temp=head;
        int x= count-n;
        for(int i=1; i<x; i++) {
            temp=temp->next;
        }

        if(count==n) head=head->next;

        if(temp->next!=NULL)
        temp->next=temp->next->next;
        return head;
    }
};