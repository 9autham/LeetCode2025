class Solution {
public:
    long long countSubarrays(vector<int>& nums, long long k) {
        long long cnt = 0, sum = 0;
        int n = nums.size();

        for(int i=0, j=0; j<n; j++){
            sum += nums[j];
            while((sum*(j-i+1)) >= k){
                sum -= nums[i];
                i++;
            }
            cnt += j-i+1;
        }
        return cnt;
    }
};