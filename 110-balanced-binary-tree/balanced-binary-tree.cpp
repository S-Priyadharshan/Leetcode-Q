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
    bool isBalanced(TreeNode* root) {
        if(root==nullptr)return true;
        int depth=0;
        bool cond=true;
        dfs(root,depth,cond);
        return cond;
    }
    int dfs(TreeNode* root,int& depth,bool& cond){
        if(cond==false)return 0;
        if(root==nullptr)return 0;
        int ld=dfs(root->left,depth,cond);
        int rd=dfs(root->right,depth,cond);
        if(abs(rd-ld)>1){
            cond=false;
            return 0;
        }
        return max(ld,rd)+1;
    }
};