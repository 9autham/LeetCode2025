class Solution {
public:
    int longestSubsequence(vector<int>& nums) {
        int xorsum = 0;
        int n= nums.size();
        for(int i=0;i<n;i++){
            xorsum = xorsum ^ nums[i];   
        }
        if(xorsum){
            return n;
        }
        for(int i=0;i<n;i++){
            int temp = xorsum;
            temp = temp ^ nums[i];
            if(temp){
                return n-1;
            }
        }
        return 0;
    }
};