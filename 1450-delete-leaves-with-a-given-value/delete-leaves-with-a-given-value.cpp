/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    void removeLeafNode(TreeNode* root,int target,TreeNode* parent,int flag){
        // if(!root)return;
        // if(root->left){
        //     removeLeafNode(root->left,target);
        // }
        // if(root->right){
        //     removeLeafNode(root->right,target);
        // }
        // cout<<root->val<<" "<<root->left<<" "<<root->right<<"\n";
        // if(root->val==target && root->left==nullptr && root->right==nullptr){
        //     // cout<<root->val<<"\n";
        //     root=nullptr;
        // }
        if(!root)return;

        if(root->left){
            removeLeafNode(root->left,target,root,1);
        }
        if(root->right){
            removeLeafNode(root->right,target,root,2);
        }
        if(root->val==target && root->left==nullptr && root->right==nullptr){
            if(parent){
                if(flag==1)parent->left=nullptr;
                else parent->right=nullptr;
            }
        }
        return;
    }
    TreeNode* removeLeafNodes(TreeNode* root, int target) {
        if(!root)return nullptr;
        removeLeafNode(root,target,nullptr,0);
        if(root->val==target && root->left==nullptr && root->right==nullptr)return nullptr;
        return root;
    }
};