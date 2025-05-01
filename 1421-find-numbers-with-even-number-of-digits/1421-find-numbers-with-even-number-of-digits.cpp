class Solution {
public:
    int findNumbers(vector<int>& nums) {
        int ans=0;
        for(int i=0;i<nums.size();i++){
            int c=0;
            while(nums[i]){
                c++;
                nums[i]=nums[i]/10;
            }
            if(c%2==0)
                ans++;
            c=0;
        }
        return ans;
    }
};