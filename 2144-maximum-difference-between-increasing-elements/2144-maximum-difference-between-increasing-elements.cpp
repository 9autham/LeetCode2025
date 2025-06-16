class Solution {
public:
    int maximumDifference(vector<int>& nums) {
        int n=nums.size();
        vector<int>v(n);
        int maxi=INT_MIN;
        for(int i=n-1;i>=0;i--){
            maxi=max(maxi,nums[i]);
            v[i]=maxi;
        }
        maxi=INT_MIN;
        for(int i=0;i<n;i++){
            maxi=max(maxi,v[i]-nums[i]);
        }
        if(maxi<=0)
            maxi=-1;
        return maxi;
    }
};