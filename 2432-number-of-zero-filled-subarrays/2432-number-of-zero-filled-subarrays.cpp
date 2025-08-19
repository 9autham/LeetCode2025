class Solution {
public:
    long long zeroFilledSubarray(vector<int>& nums) {
        long long int cnt=0;
        long long ans=0;
        int n=nums.size();
        for(int i=0;i<n;i++){
            if(nums[i]==0){
                while(i<n and nums[i]==0){
                    cnt++;
                    i++;
                }
                i--;
                ans=ans+(cnt*(cnt+1))/2;
                cnt=0;
            }
            else{
                cnt=0;
            }

        }
        ans=ans+(cnt*(cnt+1))/2;
        return ans;
    }
};