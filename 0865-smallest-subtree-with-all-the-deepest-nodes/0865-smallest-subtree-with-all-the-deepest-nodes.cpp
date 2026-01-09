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
TreeNode*lca(TreeNode*root,TreeNode*p,TreeNode*q){
        if(root==NULL or root==p or root==q)return root;
        TreeNode*l=lca(root->left,p,q);
        TreeNode*r=lca(root->right,p,q);
        if(l==NULL)return r;
        if(r==NULL)return l;
        return root;
    }
    TreeNode* subtreeWithAllDeepest(TreeNode* root) {
        TreeNode*ff=NULL;
        TreeNode*ss=NULL;
        if(root==NULL)return root;
        queue<TreeNode*>q;
        q.push(root);
        while(!q.empty()){
            int n=q.size();
            for(int i=0;i<n;i++){
                auto it=q.front();
                q.pop();
                if(it->left)q.push(it->left);
                if(it->right)q.push(it->right);
                if(i==0)ff=it;
                if(i==n-1)ss=it;
            }
        }
        return lca(root,ff,ss);
    }
};