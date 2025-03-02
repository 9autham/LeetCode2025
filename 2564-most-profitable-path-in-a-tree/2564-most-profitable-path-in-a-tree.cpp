class Solution {
public:
    bool dfs(int idx,vector<int>&vis,vector<vector<int>>&adj,vector<int>&time,int t){
        if(idx==0){
            return true;
        }
        vis[idx]=1;
        for(int i=0;i<adj[idx].size();i++){
            bool reached = false;
            if(!vis[adj[idx][i]]){
                reached = dfs(adj[idx][i],vis,adj,time,t+1);
                if(reached){
                    if(adj[idx][i])
                    time[adj[idx][i]]=t+1;
                    return true;
                }
            }
        }
        return false;
    }

    int mostProfitablePath(vector<vector<int>>& edges, int bob, vector<int>& amount) {
        int n=amount.size();
        vector<vector<int>>adj(n);
        for(int i=0;i<edges.size();i++){
            adj[edges[i][0]].push_back(edges[i][1]);
            adj[edges[i][1]].push_back(edges[i][0]);
        }
        vector<int>vis(n,0);
        vector<int>time(n,INT_MAX);
        time[bob]=0;
        dfs(bob,vis,adj,time,0);
        // Alice turn 
        queue<pair<int,pair<int,int>>>q;
        fill(vis.begin(),vis.end(),0);
        q.push({0,{0,amount[0]}}); // {idx,{seconds,amount}}
        vis[0]=1;
        int ans=INT_MIN;
        while(!q.empty()){
            int n=q.size();
            for(int i=0;i<n;i++){
                auto it=q.front();
                q.pop();
                int idx=it.first;
                int sec=it.second.first;
                int amt=it.second.second;
                // cout<<idx<<endl;
                if(adj[idx].size() == 1 && idx != 0)
                ans=max(ans,amt);
                cout<<amt<<endl;
                for(int j=0;j<adj[idx].size();j++){
                    int nidx=adj[idx][j];
                    if(vis[nidx])continue;
                    if(time[nidx]>(sec+1) || time[nidx]==INT_MAX){
                        vis[nidx]=1;
                        q.push({nidx,{sec+1,amt+(amount[nidx])}});
                    }
                    else if(time[nidx]==(sec+1)){
                        vis[nidx]=1;
                        q.push({nidx,{sec+1,amt+(amount[nidx]/2)}});
                    }
                    else{
                        vis[nidx]=1;
                        q.push({nidx,{sec+1,amt+(0)}});
                    }
                }
            }
        }
        return ans;
    }
};