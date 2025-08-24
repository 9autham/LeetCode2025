class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        int n=nums.size();
        int k=-1;
        for(int i=0;i<n;i++){
            if(nums[i]==0){
                k=i;
                break;
            }
        }
        if(k==-1)return nums.size()-1;
        int maxi=0;
        int prev=0;
        int curr=0;
        for(int i=0;i<n;i++){
            if(nums[i]==0){
                prev=curr;
                curr=0;
            }
            else{
                curr++;
            }
            maxi=max(maxi,prev+curr);
        }
        return maxi;
    }
};