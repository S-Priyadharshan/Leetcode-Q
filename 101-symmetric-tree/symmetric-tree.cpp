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
    bool isSymmetric(TreeNode* root) {
        return isSame(root->left,root->right);
    }
    bool isSame(TreeNode* TL,TreeNode* TR){
        if(TL==nullptr && TR==nullptr)return true;
        if(TL==nullptr || TR==nullptr)return false;
        if(TL->val!=TR->val)return false;
        return isSame(TL->left,TR->right) && isSame(TL->right,TR->left);
    }
};