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
    pair<int,int> helper(TreeNode* root){
        if(!root) return {0,0};
        auto lefty=helper(root->left);
        auto righty=helper(root->right);

        int sumWithParent = root->val+lefty.second+righty.second;
        int sumWithoutParent = max(lefty.first,lefty.second)+max(righty.first,righty.second);

        return {sumWithParent,sumWithoutParent};
    }
    int rob(TreeNode* root) {
        auto res=helper(root);
        return max(res.first,res.second);
    }
};