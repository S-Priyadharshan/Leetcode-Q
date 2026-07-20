/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/

class Solution {
public:
    Node* cloneGraph(Node* node) {
        if(!node)return nullptr;
        map<Node*,Node*> mp;
        if(node->neighbors.size()==0){
            Node* clone = new Node(node->val,node->neighbors);
            return clone;
        }
        return dfs(node,mp);
    }

    Node* dfs(Node* curr,map<Node*,Node*>& mp){
        Node* clone = new Node(curr->val);
        vector<Node*> neighbors;
        mp[curr]=clone;
        for(Node* nei:curr->neighbors){
            if(mp.find(nei)!=mp.end()){
                neighbors.push_back(mp[nei]);
            }else{
                neighbors.push_back(dfs(nei,mp));
            }
        }
        clone->neighbors = neighbors;
        return clone;
    }
};