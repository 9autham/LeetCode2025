class Solution {
public:
    vector<int>ans;
    void solve(int n){
        vector<int>v;
        while(n){
            v.push_back(n%10);
            n=n/10;
        }
        for(int i=v.size()-1;i>=0;i--){
            ans.push_back(v[i]);
        }
    }
    vector<int> separateDigits(vector<int>& nums) {
        for(int i=0;i<nums.size();i++){
            solve(nums[i]);
        }
        return ans;
    }
};