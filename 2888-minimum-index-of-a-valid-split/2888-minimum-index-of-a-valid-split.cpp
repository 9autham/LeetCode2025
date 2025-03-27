class Solution {
public:
    int minimumIndex(vector<int>& nums) {
        map<int,int>m;
        int n=nums.size();
        for(int i=0;i<n;i++){
            m[nums[i]]++;
        }
        int ele=-1;
        int f=0;
        for(auto val:m){
            if(f<val.second){
                f=val.second;
                ele=val.first;
            }
        }
        int pf=0;
        for(int i=0;i<n;i++){
            if(nums[i]==ele){
                pf++;
            }
            int len1=i+1;
            int len2=n-len1;
            if(2*pf>len1 and 2*(f-pf)>len2)
                return i;
        }    
        return -1;
    }
    
};