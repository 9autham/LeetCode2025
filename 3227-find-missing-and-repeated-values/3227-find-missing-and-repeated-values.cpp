class Solution {
public:
    vector<int> findMissingAndRepeatedValues(vector<vector<int>>& nums) {
        int n=nums.size();
        vector<int>v(n*n,0);
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                v[nums[i][j]-1]++;
            }
        }
        // for(int i=0;i<n;i)
        int a,b;
        for(int i=0;i<v.size();i++){
            if(v[i]==0){
                a=i+1;
            }
            if(v[i]==2){
                b=i+1;
            }
        }
        return {b,a};
    }
};