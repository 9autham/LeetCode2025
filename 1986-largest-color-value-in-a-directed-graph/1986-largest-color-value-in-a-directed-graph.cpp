class Solution {
#define vi vector<int>
#define vvi vector<vector<int>>

public:
    // kahn's bfs
    int largestPathValue(string colors, vector<vector<int>>& edges) {
        int n = colors.size(), count = 0, ans = 0;
        vvi adj(n);
        vi in_degree(n, 0);
        vvi dp(n, vi(26, 0)); 
        queue<int> kahn;

        for (vi e: edges) {
            adj[e[0]].push_back(e[1]);
            in_degree[e[1]]++;
        }

        for (int i = 0; i < n; ++i) {
            if (in_degree[i]==0) kahn.push(i);
        }

        while (!kahn.empty()) {
            int curr = kahn.front();
            kahn.pop();
            dp[curr][colors[curr]-'a']++;
            for (int c = 0; c < 26; ++c) {
                ans = max(ans, dp[curr][c]);
            }
            count++;

            for (int nbr : adj[curr]) {
                for (int c = 0; c < 26; ++c) {
                    dp[nbr][c] = max(dp[curr][c], dp[nbr][c]);
                }
                in_degree[nbr] -= 1;
                if (in_degree[nbr]==0) kahn.push(nbr);
                
            }
        }

        return count<n ? -1 : ans;
    }
};