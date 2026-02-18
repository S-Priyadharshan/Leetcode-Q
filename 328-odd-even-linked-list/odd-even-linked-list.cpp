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
    ListNode* oddEvenList(ListNode* head) {
        if(head==nullptr || head->next==nullptr)return head;
        bool odd=true;
        ListNode* ptr=head;
        ListNode* start=head->next;
        ListNode* temp;
        while(ptr->next->next!=nullptr){
            temp=ptr->next;
            ptr->next=ptr->next->next;
            ptr=temp;
            odd=!odd;
        }
        if(odd){
            ptr->next->next=nullptr;
            ptr->next=start;
        }
        else{
            ptr->next->next=start;
            ptr->next=nullptr;
        }
        return head;
    }
};