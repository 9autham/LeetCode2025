class Solution {
public:
    int search(vector<int>& nums, int target) {
        int s=0;
        int e=nums.size()-1;
        while(s<=e){
            cout<<s<<" "<<e<<endl;
            int mid=s+(e-s)/2;
            if(nums[mid]==target){
                return mid;
            }
            if(nums[mid]>=nums[0]){
                if(target>=nums[0]){
                    if(target>nums[mid]){
                        s=mid+1;
                    }
                    else{
                        e=mid-1;
                    }
                }
                else{
                    s=mid+1;
                }
            }
            else{
                if(target>=nums[0]){
                    e=mid-1;
                }
                else{
                    if(target>nums[mid]){
                        s=mid+1;
                    }
                    else{
                        e=mid-1;
                    }
                }
            }
        }
        return -1;
    }
};