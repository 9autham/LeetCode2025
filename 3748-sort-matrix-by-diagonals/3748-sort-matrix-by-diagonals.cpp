class Solution {
public:
    vector<vector<int>> sortMatrix(vector<vector<int>>& grid) {
        int n = grid.size();
        unordered_map<int, vector<int>> mp;
        for(int i=0; i<n; i++){
            for(int j=0; j<n; j++){
                mp[i-j].push_back(grid[i][j]);
            }
        }
        unordered_map<int,int> indices;
        for(auto& [diff, arr] : mp){
            if(diff < 0){
                sort(arr.begin(), arr.end());
            }
            else{
                sort(arr.begin(), arr.end(), greater<int>());
            }
            indices[diff] = 0;
        }
        vector<vector<int>> res(n, vector<int>(n, 0));
        for(int i=0; i<n; i++){
            for(int j=0; j<n; j++){
                int diff = i - j;
                res[i][j] = mp[diff][indices[diff]]; 
                indices[diff]++;
            }
        }
        return res;
    }
};