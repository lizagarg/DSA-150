class Solution {
public:
    ListNode* rotateRight(ListNode* head, int k) {
      ListNode* tail=head;
      ListNode* temp=head;

      if(!head || head->next==NULL) return head;
      int len=1;
      while(tail->next!=NULL) {
        tail=tail->next;
        len++;
      }

      if(k%len==0) return head;
      k=k%len;
      int x= len-k;

      for(int i=1; i<x; i++) {
        temp=temp->next;
      }
      tail->next=head;
      head=temp->next;
      temp->next=NULL;

      return head;
    }
};