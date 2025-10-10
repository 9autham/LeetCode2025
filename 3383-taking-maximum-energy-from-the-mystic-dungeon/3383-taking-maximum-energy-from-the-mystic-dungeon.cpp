class Solution {
public:
    int maximumEnergy(vector<int>& nums, int k) {
        int n=nums.size();
        vector<pair<int,int>>v(k);
        int maxi=INT_MIN;
        for(int i=0;i<k;i++){
            v[i].first=nums[n-i-1];
            maxi=max(maxi,nums[n-i-1]);
            v[i].second=n-i-1;
        }
        for(int i=0;i<k;i++){
            cout<<v[i].first<<" "<<v[i].second<<endl;
        }
        int idx=n-k-1;
        while(idx>=0){
            for(int i=0;i<k;i++){
                int idx1=v[i].second-k;
                int val=v[i].first;
                idx=idx1;
                if(idx>=0){
                    v[i].second=idx;
                    v[i].first+=nums[idx];
                    maxi=max(maxi,v[i].first);
                }
            }
        }
        return maxi;
    }
};