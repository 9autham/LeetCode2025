class Solution {
public:
    bool f(vector<int>&nums,int idx,int x,vector<vector<int>>&dp){
        if(x==0)return true;
        if(x<0)return false;
        if(idx==nums.size())return false;
        if(dp[idx][x]!=-1)return dp[idx][x];
        bool take=f(nums,idx+1,x-nums[idx],dp);
        bool nottake=f(nums,idx+1,x,dp);
        return dp[idx][x]=take|nottake;
    }
    bool canPartition(vector<int>& nums) {
        int s=accumulate(nums.begin(),nums.end(),0);
        int n=nums.size();
        if(s%2)return false;
        int x=s/2;
        vector<vector<int>>dp(n+1,vector<int>(x+1,-1));
        return f(nums,0,x,dp);
    }
};