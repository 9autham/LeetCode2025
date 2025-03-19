class Solution {
public:
    int minOperations(vector<int>& nums) {
        int op = 0;
        for(int i = 0; i < nums.size(); i++) {
            if(!nums[i] && i+2 >= nums.size()) return -1;
            if(!nums[i]) {
                nums[i] = 1;
                nums[i+1] = 1-nums[i+1];
                nums[i+2] = 1-nums[i+2];
                op++;
            }
        }
        return op;
    }
};