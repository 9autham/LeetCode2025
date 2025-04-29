class Solution {
public:
    long long countSubarrays(vector<int>& nums, int k) {
        int n=nums.size();
        int maxi=*max_element(nums.begin(),nums.end());
        int freq=0;
        for(auto x:nums){
            if(maxi==x){
                freq++;
            }
        }
        cout<<freq<<endl;
        if(freq<k)return 0LL;
        long long cnt=0;
        vector<int>v;
        for(int i=0;i<n;i++){
            if(nums[i]==maxi){
                v.push_back(i);
                cout<<i<<" ";
            }
        }
        v.push_back(n);
        int i=0;
        int j=k-1;
        int n1=v.size();
        long prev=0;
        while(j<(n1-1)){
            prev=(v[i]*1LL)+1LL;
            cnt=cnt+(v[i]*1LL)+1LL;
            cnt=cnt+prev*((v[j+1]-v[j]-1LL));
            j++;
            i++;
        }
        return cnt;
    }
};