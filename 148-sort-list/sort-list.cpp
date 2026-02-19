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
    ListNode* sortList(ListNode* head) {
        if(head==nullptr || head->next==nullptr)return head;

        ListNode* ptr,*slow=head,*fast=head;
        while(fast!=nullptr && fast->next!=nullptr){
            ptr=slow;
            slow=slow->next;
            fast=fast->next->next;
        }
        ptr->next=nullptr;

        ListNode* l1=sortList(head);
        ListNode* l2=sortList(slow);

        return merge(l1,l2);
    }

    ListNode* merge(ListNode* l1,ListNode* l2){
        ListNode* d=new ListNode(0),*c=d;
        while(l1!=nullptr && l2!=nullptr){
            if(l1->val<l2->val){
                c->next=l1;
                l1=l1->next;
            }else{
                c->next=l2;
                l2=l2->next;
            }
            c=c->next;
        }
        c->next=(l1!=nullptr)?l1:l2;
        return d->next;
    }
};