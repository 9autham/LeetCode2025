class Solution {
public:
    int solve(vector<int>&nums,bool e){
        int cnt=0;
        int n=nums.size();
        for(int i=0;i<n;i++){
            if((nums[i]%2==0 and e)  or (nums[i]%2==1 and !e)){
                cnt++;
                e=!e;
            }
        }
        return cnt;
    }
    int maximumLength(vector<int>& nums) {
        int n=nums.size();
        int e=0;
        for(int i=0;i<n;i++){
            if(nums[i]%2==0)e++;
        }
        int maxi=max(solve(nums,true),solve(nums,false));
        return max(maxi,max(e,n-e));
    }
};