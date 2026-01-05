class Solution {
public:
    long long maxMatrixSum(vector<vector<int>>& nums) {
        int n=nums.size();
        int m=nums[0].size();
        int neg=0;
        long long sum=0;
        int mini=INT_MAX;
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(nums[i][j]<0)neg++;
                mini=min(mini,abs(nums[i][j]));
                sum=sum+abs(nums[i][j]);
            }
        }
        if(neg%2==0)return sum;
        else return sum-2*mini;
    }
};