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
    void findInorder(TreeNode*root,vector<int>&v){
        if(root==NULL)
        return;
        findInorder(root->left,v);
        v.push_back(root->val);
        findInorder(root->right,v);
    }
    TreeNode* solve(vector<int>&v,int lb,int ub){
        if(lb>ub){
            return NULL;
        }
        int mid=(ub+lb)/2;
        TreeNode*root1=new TreeNode(v[mid]);
        root1->left=solve(v,lb,mid-1);
        root1->right=solve(v,mid+1,ub);
        return root1;
    }
    TreeNode* balanceBST(TreeNode* root) {
        vector<int>v;
        findInorder(root,v);
        return solve(v,0,v.size()-1);
    }
};