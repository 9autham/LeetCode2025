class Solution {
public:
    void f(int idx,vector<int>&vis,vector<vector<int>>&adj){
        vis[idx]=1;
        for(int i=0;i<adj[idx].size();i++){
            if(!vis[adj[idx][i]]){
                f(adj[idx][i],vis,adj);
            }
        }
    }
    int findCircleNum(vector<vector<int>>& isConnected) {
        int n=isConnected.size();
        vector<vector<int>>adj(n);
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(isConnected[i][j]){
                    adj[i].push_back(j);
                    adj[j].push_back(i);
                }
            }
        }
        vector<int>vis(n,0);
        int cnt=0;
        for(int i=0;i<n;i++){
            if(!vis[i]){
                cnt++;
                vis[i]=1;
                f(i,vis,adj);
            }
        }
        return cnt;
    }
};