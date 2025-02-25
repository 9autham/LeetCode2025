class Solution {
public:
    int numOfSubarrays(vector<int>& nums) {
        int n = nums.size();
        int even = 1, odd = 0, prefix = 0, result = 0, mod = 1e9 + 7;
        
        for (int i = 0; i < n; i++) {
            prefix += nums[i];
            if (prefix % 2 == 0) {
                result = (result + odd) % mod;
                even++;
            } else {
                result = (result + even) % mod;
                odd++;
            }
        }
        
        return result;
    }
};
