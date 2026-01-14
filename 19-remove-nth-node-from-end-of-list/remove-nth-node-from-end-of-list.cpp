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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        // int sz=0;
        // ListNode* temp=head;
        // while(temp!=nullptr){
        //     sz++;
        //     temp=temp->next;
        // }
        // int d=sz-n+1;
        // if(d==1){
        //     head=head->next;
        //     return head;
        // }
        // int cnt=1;
        // temp=head;
        // while((temp!=nullptr) && ((cnt+1)!=d)){
        //     cnt++;
        //     temp=temp->next;
        // }
        // temp->next=temp->next->next;
        // return head;
        ListNode* ptr1=head;
        ListNode *ptr2=head;
        while(ptr2!=nullptr && n){
            n--;
            ptr2=ptr2->next;
        }
        if(ptr2==nullptr){
            return head->next;
        }
        while(ptr2->next!=nullptr){
            ptr1=ptr1->next;
            ptr2=ptr2->next;
        }
        ptr1->next=ptr1->next->next;
        return head;
    }
};