class Solution {
public:
    bool isInc(vector<int>& nums){
        // 1 2 3
        int xx= -1000000;  // keep as int
        int n=nums.size();
        for(int i=0;i<n;i++){
            if(xx>=nums[i]) return false;
            xx=nums[i];
        }
        return true;
    }
    bool isDec(vector<int>& nums){
        // 3 2 1
        int xx= 1000000;  // keep as int
        int n=nums.size();
        for(int i=0;i<n;i++){
            if(xx<=nums[i]) return false;
            xx=nums[i];
        }
        return true;
    }

    long long splitArray(vector<int>& nums) {
        int n=nums.size();
        int prev = -1;
        long long sum1=0;
        int idx=0;
        long long sum = accumulate(nums.begin(), nums.end(), 0LL); // notice 0LL

        if(isInc(nums)){
            return abs(sum - 2LL * nums[n-1]);
        }
        if(isDec(nums)){
            return abs(sum - 2LL * nums[0]);
        }

        for(int i=0;i<n;i++){
            if(prev >= nums[i]){
                idx=i;
                break;
            }
            prev=nums[i];
            sum1 += nums[i];
        }

        int prev1 = 1000000;
        long long sum2=0;
        cout << prev << endl;
        cout << sum1 << endl;

        for(int i=idx;i<n;i++){
            if(prev1 <= nums[i]){
                return -1;
            }
            prev1=nums[i];
            sum2 += nums[i];
        }
        cout << sum2 << endl;
        return min(abs(sum1 - sum2), abs((sum1 - prev) - (sum2 + prev)));
    }
};
