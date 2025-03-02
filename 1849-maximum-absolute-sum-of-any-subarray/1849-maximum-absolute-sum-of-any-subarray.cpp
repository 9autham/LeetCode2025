class Solution {
public:
    int kadane(vector<int>&nums){
        int n=nums.size();
        int maxAns=0;
        int sum=0;
        for(int i=0;i<n;i++){
            sum=sum+nums[i];
            maxAns=max(maxAns,sum);
            if(sum<0){
                sum=0;
            }
        }
        return maxAns;
    }
    int maxAbsoluteSum(vector<int>& nums) {
        int maxi1=kadane(nums);
        int n=nums.size();
        for(int i=0;i<n;i++)nums[i]=nums[i]*(-1);
        int maxi2=kadane(nums);
        return max(maxi1,maxi2);
    }
};