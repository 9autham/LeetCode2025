class Solution {
public:
    long long maximumTripletValue(vector<int>& nums) {
        int n=nums.size();
        vector<int>left(n),right(n);
        left[0]=nums[0],right[n-1]=nums[n-1];
        long long ans=0;
        for(int i=1;i<n;i++) left[i]=max(left[i-1],nums[i]);
        for(int i=n-2;i>=0;i--) right[i]=max(right[i+1],nums[i]);
        for(int i=1;i<n-1;i++){
            long long r=left[i-1]-nums[i];
            if(r>0) ans=max(ans,r*right[i+1]);
        }
        return ans;
    }
};