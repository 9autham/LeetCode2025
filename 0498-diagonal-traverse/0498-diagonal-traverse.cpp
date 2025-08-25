class Solution {
public:
    vector<int> findDiagonalOrder(vector<vector<int>>& mat) {
        int n = mat.size(), m = mat[0].size();
        vector<int> res;
        map<int, vector<int>> mp;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                mp[i + j].push_back(mat[i][j]);
            }
        }

        int level = 0;
        for (auto [k, v] : mp) {
            if (level % 2 == 0) {
                reverse(v.begin(), v.end());
            }
            res.insert(res.end(), v.begin(), v.end());
            level++;
        }
        return res;
    }
};