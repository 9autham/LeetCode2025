class Solution {
public:
    int maxRotateFunction(vector<int>& nums) {
        int n = nums.size();
        long long total = 0, curr = 0;
        for (int i = 0; i < n; i++) {
            total += nums[i];
            curr += 1LL * i * nums[i];
        }

        long long res = curr;
        for (int k = 1; k < n; k++) {
            curr = curr + total - 1LL * n * nums[n - k];
            res = max(res, curr);
        }
        return (int)res;
    }
};