#define ll long long
class Solution {
public:
    // ll f(vector<int>&nums,int i,int prev){
    //     int n=nums.size();
    //     if(i==n)return 0;
    //     if(prev==-1){
    //         ll t=nums[i]*1LL+f(nums,i+1,i);
    //         ll nt=f(nums,i+1,prev);
    //         return max(t,nt);
    //     }
    //     else if(nums[i]==nums[prev]){
    //         ll t=nums[i]*1LL + f(nums,i+1,i);
    //         ll nt=f(nums,i+1,prev);
    //         return max(t,nt);
    //     }
    //     else{
    //         ll t=0;
    //         int a=nums[i]-2;
    //         int b=nums[i]+2;
    //         if(!(a<=nums[prev] or nums[prev]<=b)){
    //             t=nums[i]*1LL+f(nums,i+1,i);
    //         }
    //         ll nt=f(nums,i+1,prev);
    //         return max(t,nt);
    //     }
    // }
    ll f(vector<pair<ll,ll>>&v,int i,vector<ll>&dp){
        int n=v.size();
        if(i>=n)return 0; 
        if(dp[i]!=-1)return dp[i];
        ll ff=v[i].first;
        ll ss=v[i].second;
        ll nt=f(v,i+1,dp);
        ll t=ss;
        if(i+1<n and v[i+1].first > ff+2){
            t=t+f(v,i+1,dp);
        }
        else if(i+2<n and v[i+2].first > ff+2){
            t=t+f(v,i+2,dp);
        }
        else{
            t=t+f(v,i+3,dp);
        }
        return dp[i]=max(t,nt);
    }
    long long maximumTotalDamage(vector<int>& nums) {
        map<int,int>m;
        int n=nums.size();
        for(int i=0;i<n;i++){
            m[nums[i]]++;
        }
        vector<pair<ll,ll>>v;
        for(auto it:m){
            ll a=it.first;
            ll b=a*1LL*(it.second);
            v.push_back({a,b});
        }
        vector<ll>dp(n+10,-1);
        return f(v,0,dp);
    }
};