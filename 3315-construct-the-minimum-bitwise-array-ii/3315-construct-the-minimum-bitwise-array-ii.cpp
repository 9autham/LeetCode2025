class Solution {
public:
    vector<int> minBitwiseArray(vector<int>& nums) {
        vector<int> result(nums.size());
        for (int i = 0; i < (int)nums.size(); i++) {
            int v = nums[i];
            result[i] = (v == 2) ? -1 : calc(v);
        }
        return result;
    }

    static int calc(int value) {
        int bitsOnRight = 0;
        int v = value;
        while ((v & 1) != 0) {
            bitsOnRight++;
            v >>= 1;
        }
        if (bitsOnRight == 1) return value - 1;
        int woBitsOnRight = value ^ ((1 << bitsOnRight) - 1);
        return woBitsOnRight | ((1 << (bitsOnRight - 1)) - 1);
    }
};