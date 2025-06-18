class Solution {
public:
    vector<vector<int>> divideArray(vector<int>& nums, int k) {
        sort(nums.begin(),nums.end());
        vector<vector<int>>ans,ab;
        int i=0;
        int j=2;
        int n=nums.size();
        while(j<n){
            if(abs(nums[i]-nums[j])<=k){
                vector<int>v;
                for(int k=i;k<=j;k++){
                    v.push_back(nums[k]);
                }
                ans.push_back(v);
            }
            else{
                return ab;
            }
            j=j+3;
            i=i+3;
        }
        return ans;
    }
};