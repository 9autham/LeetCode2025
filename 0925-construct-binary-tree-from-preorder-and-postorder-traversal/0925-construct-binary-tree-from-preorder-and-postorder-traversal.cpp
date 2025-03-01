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
    int indx=0;
    TreeNode* f(int st, int en, vector<int>&pre, vector<int>&post, map<int,int>postIdx) {
        if (indx >= pre.size() || st > en) return nullptr; 
        if(st==en){
            return new TreeNode(pre[indx++]);
        }
        TreeNode * root = new TreeNode(pre[indx++]);
        int idx = postIdx[pre[indx]]; // check of next element
        root->left = f(st,idx,pre,post,postIdx);
        root->right= f(idx+1,en-1,pre,post,postIdx);
        return root;
    }
    
    TreeNode* constructFromPrePost(vector<int>& preorder, vector<int>& postorder) {
        map<int,int>postIdx;
        int n=preorder.size();
        int cnt=0;
        for(auto it:postorder){
            postIdx[it]=cnt;
            cnt++;
        }
        return f(0,n-1,preorder,postorder, postIdx);
    }
};