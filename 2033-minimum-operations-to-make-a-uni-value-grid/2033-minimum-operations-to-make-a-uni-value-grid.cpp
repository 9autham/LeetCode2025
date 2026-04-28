class Solution {
public:
    int minOperations(vector<vector<int>>& grid, int x) {
        
        int n = grid.size();
        int m = grid[0].size();

        int rem = grid[0][0]%x;
        vector<int>vec;

        for(int i = 0; i < n; i++)
        {
            for(int j = 0; j < m; j++)
            {
                if(grid[i][j]%x != rem)
                return -1;

                vec.push_back(grid[i][j]);
            }
        }

        sort(vec.begin(), vec.end());
        int mid = vec.size()/2;

        int cnt = 0;

        for(int i = 0; i < vec.size(); i++)
        cnt += (abs(vec[i] - vec[mid]))/x;
        
        return cnt;
    }
};