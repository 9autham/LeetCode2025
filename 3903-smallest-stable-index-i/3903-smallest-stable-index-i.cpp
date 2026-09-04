class Solution {
public:
    int firstStableIndex(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int>mini(n),maxi(n);
        int mn=INT_MAX;
        for(int i=n-1;i>=0;i--){
            mn=min(mn,nums[i]);
            mini[i]=mn;
        }
        int mx=INT_MIN;
        for(int i=0;i<n;i++){
            mx=max(mx,nums[i]);
            maxi[i]=mx;
        }
        int mi=INT_MAX;
        int idx = -1;
        for(int i=0;i<n;i++){
            int xx= maxi[i]-mini[i];
            if(xx<=k){
                return i;
            }
            mi=min(xx,mi);
        }
        return idx;
    }
};