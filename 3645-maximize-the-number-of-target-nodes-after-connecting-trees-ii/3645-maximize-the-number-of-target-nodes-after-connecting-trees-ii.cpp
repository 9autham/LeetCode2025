#define vi vector<int>
#define vvi vector<vi>
#define pb push_back
class Solution {
    void dfs(int src, int par, const auto &adj, auto &t) {
        t[0][src] = 1, t[1][src] = 0;
        for(const auto &next: adj[src]) {
            if(next != par) {
                dfs(next, src, adj, t);
                t[0][src] += t[1][next];
                t[1][src] += t[0][next];
            }
        }
    }
    void dfs2(int src, int par, const auto &adj, auto &t) {
        if(par != -1) {
            t[0][src] = t[1][par];
            t[1][src] = t[0][par];
        }
        for(const auto &next: adj[src]) {
            if(next != par) {
                dfs2(next, src, adj, t);
            }
        }
    }
public:
    vector<int> maxTargetNodes(vector<vector<int>>& edges1, vector<vector<int>>& edges2) {
        int n = edges1.size() + 1;
        int m = edges2.size() + 1;

        vvi adj1(n), adj2(m);

        for(const auto &e:edges1) {
            adj1[e[0]].pb(e[1]);
            adj1[e[1]].pb(e[0]);
        }
        for(const auto &e:edges2) {
            adj2[e[0]].pb(e[1]);
            adj2[e[1]].pb(e[0]);
        }

        vvi t1(2, vi(n, 0)), t2(2, vi(m, 0));
        dfs(0, -1, adj1, t1);
        dfs(0, -1, adj2, t2);

        dfs2(0, -1, adj1, t1);
        dfs2(0, -1, adj2, t2);
        
        vi ans(n, 0);
        int mx = 0;
        for(int i=0;i<m;i++) mx=max(mx, t2[1][i]);
        
        for(int i=0;i<n;i++) {
            ans[i] = mx + t1[0][i];
        }
        
        return ans;
    }
};