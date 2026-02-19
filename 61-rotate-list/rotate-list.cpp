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
    ListNode* rotateRight(ListNode* head, int k) {
        if(!head)return head;
        ListNode* ptr=head;
        int n=1;
        while(ptr->next){
            ptr=ptr->next;
            n++;
        }
        ptr->next=head;
        if(k%=n){
            for(int i=0;i<n-k;i++)ptr=ptr->next;
        }
        head=ptr->next;
        ptr->next=nullptr;
        return head;
    }
};