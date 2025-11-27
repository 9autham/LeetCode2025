#define ll long long

class Solution {
public:
    long long maxSubarraySum(vector<int>& nums, int k) {
        int n = nums.size();
        ll maxSum = LLONG_MIN;
        vector<ll> prefixSum(n + 1, 0);
        for (int i = 0; i < n; ++i) {
            prefixSum[i + 1] = prefixSum[i] + nums[i];
        }

        vector<ll> mod(k, LLONG_MAX);

        for (int i = 0; i <= n; ++i) {
            int remainder = i % k;
            if (mod[remainder] != LLONG_MAX) {
                maxSum = max(maxSum, prefixSum[i] - mod[remainder]);
            }
            mod[remainder] = min(mod[remainder], prefixSum[i]);
        }

        return maxSum;
    }
};

