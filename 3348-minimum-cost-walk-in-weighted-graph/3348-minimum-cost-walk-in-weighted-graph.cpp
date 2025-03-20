class Solution {
public:
    void dfs(vector<vector<pair<int,int>>>&adj,int i,vector<int>&vis,vector<int>&v,int &nd){
        vis[i]=1;
        v.push_back(i);
        for(auto it:adj[i]){
            int next=it.first;
            int w=it.second;
            if(!vis[next]){
                nd=nd&w;
                dfs(adj,next,vis,v,nd);
            }
        }
        return;
    }
    vector<int> minimumCost(int n, vector<vector<int>>& edges, vector<vector<int>>& q) {
        vector<vector<pair<int,int>>>adj(n);
        for(int i=0;i<edges.size();i++){
            adj[edges[i][0]].push_back({edges[i][1],edges[i][2]});
            adj[edges[i][1]].push_back({edges[i][0],edges[i][2]});
        }
        vector<int>vis(n,0);
        vector<pair<int,int>>ans(n);
        for(int i=0;i<n;i++){
            vector<int>v;
            int nd=INT_MAX;
            if(!vis[i]){
                dfs(adj,i,vis,v,nd);
            }
            for(int j=0;j<v.size();j++){
                cout<<v[j]<<" ";
                for(auto it: adj[v[j]]){
                    nd=nd&it.second;
                }
            }
            for(int j=0;j<v.size();j++){
                ans[v[j]]={nd,i};
            }
            cout<<"nd "<<nd<<endl;
            cout<<endl;
        }
        for(int i=0;i<n;i++){
            cout<<"ans "<<ans[i].first<<" "<<ans[i].second<<endl;
        }
        vector<int>ret;
        for(int i=0;i<q.size();i++){
            int x=q[i][0];
            int y=q[i][1];
            if(x==y){
                ret.push_back(0);
                continue;
            }
            if(ans[x].second!=ans[y].second){
                ret.push_back(-1);
            }
            else{
                ret.push_back(ans[x].first);
            }
        }
        for(auto it:ret){
            if(it==INT_MAX)it=0;
        }
        return ret;
    }
};
// [[1,2,7],[1,2,7],[3,2,9],[1,3,12],[2,3,4],[0,2,12],[3,1,10],[2,1,3]]