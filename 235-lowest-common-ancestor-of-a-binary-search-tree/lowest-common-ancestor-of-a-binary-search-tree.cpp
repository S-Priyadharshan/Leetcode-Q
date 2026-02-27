/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        // vector<TreeNode*> forp;
        // vector<TreeNode*> forq;
        // TreeNode* temp=root;
        // while(temp->val!=p->val){
        //     forp.push_back(temp);
        //     if(p->val<temp->val)temp=temp->left;
        //     else temp=temp->right;
        // }
        // forp.push_back(temp);
        // temp=root;
        // while(temp->val!=q->val){
        //     forq.push_back(temp);
        //     if(q->val<temp->val)temp=temp->left;
        //     else temp=temp->right;
        // }
        // forq.push_back(temp);
        // TreeNode* ans=root;
        // int sz=min(forp.size(),forq.size());
        // for(int i=0;i<sz;i++){
        //     if(forp[i]==forq[i])ans=forp[i];
        //     else break;
        // }
        // return ans;
        if(root->val>p->val && root->val>q->val){
            return lowestCommonAncestor(root->left,p,q);
        }else if(root->val<p->val && root->val<q->val){
            return lowestCommonAncestor(root->right,p,q);
        }else{
            return root;
        }
    }
};