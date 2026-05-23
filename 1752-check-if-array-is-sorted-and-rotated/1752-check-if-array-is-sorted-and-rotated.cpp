class Solution {
public:
    bool check(vector<int>& nums) {
        int idx=-1;
        for(int i=0;i<nums.size()-1;i++){
            if(nums[i]<=nums[i+1]){
                continue;
            }
            else{
                idx=i;
                break;
            }
        }
        cout<<"idx "<<idx;
        if(idx==-1)
            return true;
        else{
            for(int i=idx;i>=1;i--){
                if(nums[i]>=nums[i-1])
                    continue;
                return false;
            }
            for(int i=idx+1;i<nums.size()-1;i++){
                if(nums[i]<=nums[i+1])
                    continue;
                return false;
            }
        }
        if(nums[0]<nums[nums.size()-1])
            return false;
        return true;
    }
};