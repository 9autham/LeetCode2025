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

TreeNode* f(vector<int>& preorder, map<int, int>& m, int& idx, int st, int end) {
        if (st > end || idx >= preorder.size()) {
            return nullptr;
        }

        TreeNode* root = new TreeNode(preorder[idx]);
        idx++;

        if (st == end) {
            return root;
        }

        int postIdx = m[preorder[idx]];

        root->left = f(preorder, m, idx, st, postIdx);
        root->right = f(preorder, m, idx, postIdx + 1, end - 1);

        return root;
    }

    TreeNode* constructFromPrePost(vector<int>& preorder, vector<int>& postorder) {
        int n = preorder.size();
        map<int, int> m;
        for (int i = 0; i < n; i++) {
            m[postorder[i]] = i;
        }

        int idx = 0;
        return f(preorder, m, idx, 0, n - 1);
    }
};