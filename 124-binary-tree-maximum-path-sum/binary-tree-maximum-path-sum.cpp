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
    int mx=INT_MIN;
    int maxPathSum(TreeNode* root) {
        if(!root)return 0;
        maxgain(root);
        return mx;
    }
    int maxgain(TreeNode* root){
        if(!root)return 0;
        int leftgain=max(maxgain(root->left),0);
        int rightgain=max(maxgain(root->right),0);
        mx=max(mx,leftgain+rightgain+root->val);
        return root->val+max(leftgain,rightgain);
    }
};