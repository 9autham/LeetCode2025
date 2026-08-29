class Solution {
public:
    vector<int> lexicographicallySmallestArray(vector<int>& nums, int limit) {
        int n=nums.size();
        vector<pair<int,int>>vp;
        for(int i=0;i<n;i++){
            vp.push_back({nums[i],i});
        }
        sort(vp.begin(),vp.end());
        vector<int>dp(n,1);
        for(int i=1;i<n;i++){
            if(abs(vp[i].first-vp[i-1].first)<=limit){
                dp[i]=dp[i-1];
            }
            else{
                dp[i]=dp[i-1]+1;
            }
        }
        vector<int>ans(n);
        int xx=1;
        int lastidx=0;
        for(int i=0;i<n;i++){
            cout<<dp[i]<<" ";
        }
        for(int i=0;i<n;i++){
            if(dp[i]==xx){
                continue;
            }
            else{
                vector<int>vi;
                for(int j=lastidx;j<i;j++){
                    vi.push_back(vp[j].second);
                }
                sort(vi.begin(),vi.end());
                int ii=0;
                for(int j=lastidx;j<i;j++){
                    ans[vi[ii++]]=vp[j].first;
                }
                xx++;
                lastidx=i;
                i--;
            }
        }
        vector<int>vi;
        for(int j=lastidx;j<n;j++){
            vi.push_back(vp[j].second);
        }
        sort(vi.begin(),vi.end());
        int ii=0;
        for(int j=lastidx;j<n;j++){
            ans[vi[ii++]]=vp[j].first;
        }
        return ans;
    }
};