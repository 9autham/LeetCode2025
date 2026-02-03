class Solution {
public:
    bool check1(vector<int>&nums,int st,int en){
        for(int i=st;i<en;i++){
            if(nums[i]>=nums[i+1]){
                return false;
            }
        }
        return true;
    }

    
    bool check2(vector<int>&nums,int st,int en){
        for(int i=st;i<en;i++){
            if(nums[i]<=nums[i+1]){
                return false;
            }
        }
        return true;
    }

    bool isTrionic(vector<int>& nums) {
        int p=0,q=0,n=nums.size();

        for(int i=1;i<nums.size();i++){
            if(nums[i]<nums[i-1]){
                p=i-1;
                break;
            }
        }

        for(int i=n-2;i>=0;i--){
            if(nums[i]>nums[i+1]){
                q=i+1;
                break;
            }
        }
        if(p==0 || q==n-1)return false;

        return (check1(nums,0,p)&&check2(nums,p,q)&&check1(nums,q,n-1));
    }
};