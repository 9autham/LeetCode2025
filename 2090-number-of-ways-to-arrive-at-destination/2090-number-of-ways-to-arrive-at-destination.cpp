#define ll long long
class Solution {
public:
    int mod=1e9+7;
    int countPaths(int n, vector<vector<int>>& roads) {
        vector<vector<pair<ll,ll>>>adj(n);
        for(auto val:roads){
            int x=val[0];
            int y=val[1];
            int wt=val[2];
            adj[x].push_back({y,wt});
            adj[y].push_back({x,wt});
        }
        vector<long long>v(n,0);
        vector<ll>dist(n,1e15);
        priority_queue <pair<ll,ll>, vector<pair<ll,ll>>, greater<pair<ll,ll>> > pq;
        pq.push({0,0});
        v[0]=1LL;
        while(!pq.empty()){
            auto it=pq.top();
            pq.pop();
            ll dis=it.first;
            ll node=it.second;
            for(auto val:adj[node]){
                ll wgt=val.second;
                ll ad=val.first;
                if(dis+wgt<dist[ad]){
                    dist[ad]=dis+wgt;
                    v[ad]=v[node];
                    pq.push({dist[ad],ad});
                }
                else if(dis+wgt==dist[ad]){
                    v[ad]=(v[ad]+v[node]*1LL)%mod;
                }
            }
        }
        return v[n-1]%mod;
    }
};