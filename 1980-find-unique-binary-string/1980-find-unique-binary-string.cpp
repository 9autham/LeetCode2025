class Solution {
public:
    bool ifins(string s,vector<string>&nums){
        for(int i=0;i<nums.size();i++){
            if(nums[i]==s){
                return false;
            }
        }
        return true;
    }
    void solve(int idx,vector<string>&nums,string &s,string &ans){
        if(idx==s.size()){
            if(ifins(s,nums)){
                ans=s;
            }
            return;
        }
        s[idx]='1';
        solve(idx+1,nums,s,ans);
        s[idx]='0';
        solve(idx+1,nums,s,ans);
    }
    string findDifferentBinaryString(vector<string>& nums) {
        string s="";
        for(int i=0;i<nums[0].size();i++){
            s.push_back('0');
        }
        string ans="";
        solve(0,nums,s,ans);
        return ans;
    }
};