class Solution {
public:
    bool isDistinct(vector<int>nums)
    {
        unordered_map<int,int>mp;
        for(int i=0;i<nums.size();i++)
        {
            mp[nums[i]]++;
        }
        for(auto it:mp)
        {
            if(it.second!=1) return false;
        }
        return true;
    }
    int minimumOperations(vector<int>& nums) {
        int cnt=0;
        for(int i=0;i<nums.size();i+=3)
        {
            vector<int>temp(nums.begin()+i,nums.end());
            if(!isDistinct(temp)) cnt+=1;
            if(isDistinct(temp)) break;
        }
        return cnt;
    }
};