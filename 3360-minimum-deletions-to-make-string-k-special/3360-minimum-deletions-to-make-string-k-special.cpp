class Solution {
public:
    int minimumDeletions(string nums, int k) {
        vector<int>freq(26,0);
        int n=nums.size();
        for(int i=0;i<n;i++){
            freq[nums[i]-'a']++;
        }
        int mini=INT_MAX;
        for(int i=0;i<26;i++){
            int fix2=max(0,freq[i]-k);
            int fix1=freq[i]+k;
            int ans=0;
            for(int j=0;j<26;j++){
                if(i==j)continue;
                if(freq[j]>=fix1){
                    ans=ans+abs(freq[j]-fix1);
                }
                else if(freq[j]<freq[i]){
                    ans=ans+freq[j];
                }
            }
            mini=min(mini,ans);
            ans=0;
            for(int j=0;j<26;j++){
                if(i==j)continue;
                if(freq[j]>=freq[i]){
                    ans=ans+abs(freq[i]-freq[j]);
                }
                else if(freq[j]<fix2){
                    ans=ans+freq[j];
                }
            }
            mini=min(mini,ans);
        }
        return mini;
    }
};