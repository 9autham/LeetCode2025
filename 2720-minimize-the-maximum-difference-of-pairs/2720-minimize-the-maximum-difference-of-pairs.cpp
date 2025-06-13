class Solution {
public:
    bool ispos(int mid,vector<int>&nums,int p){
        int n=nums.size();
        int cnt=0;
        for(int i=0;i<n-1;i++){
            int x=abs(nums[i]-nums[i+1]);
            if(x<=mid){
                cnt++;
                i++;
            }
        }
        return cnt>=p;
    }
    int minimizeMax(vector<int>& nums, int p) {
        int n=nums.size();
        sort(nums.begin(),nums.end());
        int l=0;
        int h=abs(nums[0]-nums[n-1]);
        int mini=1e9;
        while(l<=h){
            int mid=(l+(h-l)/2);
            if(ispos(mid,nums,p)){
                mini=mid;
                h=mid-1;
            }
            else{
                l=mid+1;
            }
        }
        return mini;
    }
};