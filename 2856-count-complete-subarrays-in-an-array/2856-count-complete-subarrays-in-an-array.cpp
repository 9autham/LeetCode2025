class Solution {
public:
    int countCompleteSubarrays(vector<int>& nums) {
        map<int,int>m;
        int n=nums.size();
        for(auto x:nums){
            m[x]++;
        }
        int cnt=0;
        int si=m.size();
        for(int i=0;i<n;i++){
            map<int,int>mp;
            for(int j=i;j<n;j++){
                mp[nums[j]]++;
                if(mp.size()==si){
                    cnt++;
                }
            }
        }
        return cnt;
    }
};