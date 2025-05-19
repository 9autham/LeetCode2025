class Solution {
public:
    string triangleType(vector<int>& nums) {
        if(nums[0]==nums[1] and nums[1]==nums[2])return "equilateral";
        set<int>s;
        int ab=nums[0]+nums[1];
        int bc=nums[1]+nums[2];
        int ca=nums[0]+nums[2];
        if(ca<=nums[1] or bc<=nums[0] or ab<=nums[2])return "none";
        s.insert(nums[0]);
        s.insert(nums[1]);
        s.insert(nums[2]);
        if(s.size()==2)return "isosceles";
        else return "scalene";
    }
};