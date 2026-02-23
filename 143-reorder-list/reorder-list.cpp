/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    void reorderList(ListNode* head) {
       ListNode* slow=head;
       ListNode* fast=head;
       while(fast!=nullptr && fast->next!=nullptr){
        slow=slow->next;
        fast=fast->next->next;
       }
       ListNode* prev=nullptr;
       ListNode* temp;
       ListNode* curr=slow->next;
       slow->next=nullptr;
       while(curr!=nullptr){
        temp=curr->next;
        curr->next=prev;
        prev=curr;
        curr=temp;
       }
       ListNode* h1=head;
       ListNode* h2=prev;
       ListNode* t1,*t2;
       while(h1!=nullptr && h2!=nullptr){
        t1=h1->next;
        t2=h2->next;
        h1->next=h2;
        h2->next=t1;
        h1=t1;
        h2=t2;
       }
    }
};
