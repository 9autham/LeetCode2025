class Solution {
public:
    bool kLengthApart(vector<int>& nums, int k) {
        int dif = 0, prevPos = -(nums.size()), curPos = 0;
        for(int i = 0; i < nums.size(); ++i)
        {
            if(nums[i] == 1)
            {
                curPos = i;
                dif = curPos-prevPos;
                if(dif-1 < k && curPos != 0)
                    return false;
                prevPos = curPos;
            }
        }
        return true;
    }
};