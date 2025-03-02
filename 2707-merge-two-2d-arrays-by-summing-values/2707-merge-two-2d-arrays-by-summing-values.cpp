class Solution {
public:
    vector<vector<int>> mergeArrays(vector<vector<int>>& nums1, vector<vector<int>>& nums2) {
        int n=nums1.size();
        int m=nums2.size();
        map<int,int>mp;
        for(int i=0;i<n;i++){
            mp[nums1[i][0]]=nums1[i][1];
        }
        for(int i=0;i<m;i++){
            mp[nums2[i][0]]+=nums2[i][1];                
        }
        vector<vector<int>>ans;
        for(auto val:mp){
            vector<int>v(2);
            v[0]=val.first;
            v[1]=val.second;
            ans.push_back(v);
        }
        return ans;
    }
};