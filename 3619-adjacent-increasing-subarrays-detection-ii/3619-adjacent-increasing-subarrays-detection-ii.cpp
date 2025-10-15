class Solution {
public:
    int maxIncreasingSubarrays(vector<int>& nums) {
        int n=nums.size();
        int prev=0;
        int curr=0;
        int temp=INT_MAX;
        int ans=0;
        int maxcurr=0;
        for(int i=0;i<n;i++){
            if(temp>=nums[i]){
                prev=curr;
                curr=1;
            }
            else{
                curr++;
            }
            temp=nums[i];
            ans=max(ans,min(prev,curr));
            maxcurr=max(maxcurr,curr);
        }
        return max(ans,maxcurr/2);
    }
};