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
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        map<int,int>mp;
        for(int i=0;i<inorder.size();i++){
            mp[inorder[i]]=i;
        }
        int preIdx=0;
        return build(preorder,mp,0,inorder.size()-1,preIdx);
    }

    TreeNode* build(vector<int>& preorder,map<int,int>&mp,int start,int end,int& preIdx){
        if(start>end)return nullptr;
        TreeNode* root = new TreeNode(preorder[preIdx++]);
        int mid=mp[root->val];
        root->left = build(preorder,mp,start,mid-1,preIdx);
        root->right = build(preorder,mp,mid+1,end,preIdx);
        return root;
    }
};