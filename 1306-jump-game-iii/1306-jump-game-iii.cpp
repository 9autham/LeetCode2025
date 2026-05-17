class Solution {
public:
    bool f(vector<int>&arr,int node,vector<int>&vis){
        if(arr[node]==0)return true;
        int n=arr.size();
        vis[node]=1;
        int x=arr[node];
        if((node-x)>=0 and !vis[node-x]){
            if(f(arr,node-x,vis)==true)return true;
        }
        if((node+x)<n and !vis[node+x]){
            if(f(arr,node+x,vis)==true)return true;
        }
        return false;
    }
    bool canReach(vector<int>& arr, int start) {
        int n=arr.size();
        vector<int>vis(n,0);
        return f(arr,start,vis);
    }
};