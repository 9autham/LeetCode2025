class Solution {
public:
    long long minCost(string s, vector<int>& nums) {
        long long ans=0;
        int n=nums.size();
        map<int,int>m;
        vector<long long>cost(26);
        for(int i=0;i<n;i++){
            cost[s[i]-'a']+=nums[i];
            m[s[i]]++;
        }
        if(m.size()<=1){
            return 0;
        }
        long long sum=accumulate(nums.begin(),nums.end(), 0LL);
        cout<<sum<<endl;
        long long mini=1e15;
        cout<<sum<<endl;
        for(int i=0;i<26;i++){
            mini=min(mini, sum-cost[i]);
        }
        return mini;
    }
};