class Solution {
public:
    long long maxProfit(vector<int>& prices, vector<int>& strategy, int k) {
        long long a=0,mod=0;
        int k2=k/2,n=prices.size();
        vector<long long> p(n+1);
        p[0]=0;
        for(int i=1;i<=n;i++)
        {
            p[i]+=p[i-1]+prices[i-1]*strategy[i-1];
            if(i>k2)
            a+=prices[i-1];
            if(i>k)
            a-=prices[i-1-k2];
            if(i>=k) {
                mod=max(mod,a-(p[i]-p[i-k]));
            }
        } 
        return p[n]+mod;
    }
};