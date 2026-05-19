class Solution {
public:
    int getCommon(vector<int>& nums1, vector<int>& nums2) {
        map<int,int>m;
        for(int i=0;i<nums1.size();i++){
            m[nums1[i]]++;
        }
        int ans=-1;
        for(int i=0;i<nums2.size();i++){
            if(m[nums2[i]]){
                ans=nums2[i];
                break;
            }
        }
        return ans;
    }
};