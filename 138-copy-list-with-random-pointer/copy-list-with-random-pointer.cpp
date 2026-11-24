/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {
        if(!head)return nullptr;
        // unordered_map<Node*,Node*> mp;
        // Node* curr=head;
        // while(curr!=nullptr){
        //     mp[curr]=new Node(curr->val);
        //     curr=curr->next;
        // }
        // curr=head;
        // while(curr!=nullptr){
        //     Node* copy=mp[curr];
        //     copy->next=mp[curr->next];
        //     copy->random=mp[curr->random];
        //     curr=curr->next;
        // }
        // return mp[head];

        Node* curr=head;
        while(curr){
            Node* newnode=new Node(curr->val);
            Node* next=curr->next;
            curr->next=newnode;
            newnode->next=next;
            curr=next;
        }
        curr=head;
        while(curr && curr->next!=nullptr){
            if(curr->random) curr->next->random = curr->random->next;
            curr=curr->next->next;
        }

        Node* oldhead=head;
        Node* orghead=head->next;
        Node* newhead=head->next;

        while(oldhead){
            oldhead->next=oldhead->next->next;
            if(newhead->next){
                newhead->next=newhead->next->next;
            }
            oldhead=oldhead->next;
            newhead=newhead->next;
        }
        return orghead;
    }
};