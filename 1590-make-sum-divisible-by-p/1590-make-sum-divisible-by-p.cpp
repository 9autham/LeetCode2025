class Solution {
public:
    int minSubarray(vector<int>& nums, int p) {
        int remainder = 0, prefixSum = 0; 
        int n = nums.size(), minLen = n;
        for (int num : nums) {
            remainder = (remainder + num) % p; 
        }
        cout <<remainder<<endl;
        unordered_map<int,int> prefixSumToIndex;
        prefixSumToIndex[prefixSum] = -1;
        for (int i = 0; i < n; ++i) {
            prefixSum = (prefixSum + nums[i]) % p;
            prefixSumToIndex[prefixSum] = i;
            int key = (prefixSum - remainder + p) % p;
            if (prefixSumToIndex.find(key) != prefixSumToIndex.end()) {
                minLen = min(minLen, i - prefixSumToIndex[key]);
            }
        }
        return minLen == n ? -1 : minLen;
    }
};