class Solution {
public:
    long long getDescentPeriods(vector<int>& prices) {
        long long ans=1;
        int n=prices.size();
        long long cnt=1;
        int prev=prices[0];
        for(int i=1;i<n;i++){
            if(prev-1==prices[i]){
                cnt++;
                ans+=cnt;
                cout<<ans<<" ";
            }
            else{
                cnt=1;
                ans+=cnt;
            }
            prev=prices[i];
        }
        return ans;
    }
};