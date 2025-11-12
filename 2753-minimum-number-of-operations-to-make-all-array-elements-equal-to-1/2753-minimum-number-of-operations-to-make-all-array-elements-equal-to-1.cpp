class Solution {
public:
    
    int minOperations(vector<int>& nums) {
        int t = INT_MAX, count = 0;
        for(auto n: nums){ if(n == 1) count++; }
        if(count > 0) { return nums.size() - count; }
        for(int i = 0; i<nums.size(); ++i ){
            int last = nums[i];
            for(int j = i+1; j < nums.size(); ++j ){
                last = __gcd(last, nums[j]);
                if(last == 1) { t = min(t, j-i); break; }
            }
        }
        if(t != INT_MAX) return t + nums.size()-1;
        return -1;
    }
};