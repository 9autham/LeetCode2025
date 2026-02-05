class Solution {
public:
    vector<int> constructTransformedArray(vector<int>& nums) {
        int n=nums.size();
        vector<int>v(n);
        for(int i=0;i<n;i++){
            if(nums[i]>=0){
                int idx=(i+nums[i])%n;
                v[i]=nums[idx];
            }
            else{
                int idx=(i+100*n+nums[i])%n;
                v[i]=nums[idx];
            }
        }
        return v;
    }
};