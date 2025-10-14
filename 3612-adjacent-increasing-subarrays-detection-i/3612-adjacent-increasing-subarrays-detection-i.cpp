class Solution {
public:
    bool f(vector<int>&nums,int ii, int k){
        int temp=nums[ii];
        for(int i=ii+1;i<ii+k and i<nums.size();i++){
            if(temp>=nums[i])return false;
            temp=nums[i];
        }
        temp=nums[ii+k];
        for(int i=ii+k+1;i<(ii+k+k) and i<nums.size();i++){
            if(temp>=nums[i])return false;
            temp=nums[i];
        }
        return true;
    }
    bool hasIncreasingSubarrays(vector<int>& nums, int k) {
        int n=nums.size();
        for(int i=0;i<n;i++){
            if(((i+2*k-1)<n) and f(nums,i,k)){
                return true;
            }
        }
        return false;
    }
};