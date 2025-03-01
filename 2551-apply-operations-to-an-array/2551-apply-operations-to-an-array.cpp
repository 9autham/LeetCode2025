class Solution {
public:
    vector<int> applyOperations(vector<int>& nums) {
        for(int i=0;i<nums.size()-1;i++){
            if(nums[i]==nums[i+1]){
                nums[i]=nums[i]*2;
                nums[i+1]=0;
            }
        }
        vector<int>v;
        int c=0;
        for(int i=0;i<nums.size();i++){
            if(nums[i]==0)
                c++;
            else
                v.push_back(nums[i]);
        }
        for(int i=0;i<c;i++){
            v.push_back(0);
        }
        return v;
    }
};