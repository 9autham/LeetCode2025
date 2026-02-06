class Solution {
public:
    int minRemoval(vector<int>& nums, long long k) {
        int n = nums.size();
        sort(begin(nums), end(nums));

        int ans = n-1;

        int startIndex = 0, endIndex = 0;
        while(endIndex < n && startIndex < n){
            while(endIndex < n && nums[endIndex] <= k * nums[startIndex]){
                endIndex++;
            }

            ans = min(ans, n - (endIndex - startIndex));
            startIndex++;
        }

        return ans;
    }
};