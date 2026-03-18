class Solution {
public:
    int countSubmatrices(vector<vector<int>>& nums, int k) {
        int n=nums.size();
        int m=nums[0].size();
        int cnt=0;
        int sum=0;
        vector<vector<int>>g=nums;
        for(int i=0;i<n;i++){
            int s=0;
            for(int j=0;j<m;j++){
                s=s+nums[i][j];
                g[i][j]=s;
            }
        }
        int c1=0;
        // Start
        for(int i=0;i<m;i++){
            int s=0;
            for(int j=0;j<n;j++){
                s=s+g[j][i];
                if(s<=k){
                    c1++;
                }
                else{
                    break;
                }
            }
        }
        return c1;
    }
};