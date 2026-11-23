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
    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode* curr=head;
        ListNode* prevTail=nullptr;

        while(curr){
            ListNode* kth=returnKth(curr,k);
            
            if(!kth){
                if(prevTail)prevTail->next=curr;
                break;
            }
            ListNode* groupnext=kth->next;
            kth->next=nullptr;

            reverse(curr);

            if(curr==head){
                head=kth;
            }else{
                prevTail->next=kth;
            }

            prevTail=curr;
            curr=groupnext;
        }
        return head;
    }

    ListNode* reverse(ListNode* head){
        ListNode* curr=head;
        ListNode* prev=nullptr;
        while(curr){
            ListNode* temp=curr->next;
            curr->next=prev;
            prev=curr;
            curr=temp;
        }
        return prev;
    }

    ListNode* returnKth(ListNode* head,int k){
        k--;
        ListNode* curr=head;
        while(curr && k>0){
            curr=curr->next;
            k--;
        }
        return curr;
    }
};