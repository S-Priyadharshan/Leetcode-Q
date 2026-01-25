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
    ListNode* removeElements(ListNode* head, int val) {
        if(head==nullptr)return head;
        ListNode* temp=new ListNode();
        temp->next=head;
        while(temp!=nullptr){
            if(temp->next!=nullptr && temp->next->val==val){
                if(temp->next==head){
                    head=temp->next->next;
                }else{
                    temp->next=temp->next->next;
                }
            }else{
                temp=temp->next;
            }
        }
        return head;       
    }
};