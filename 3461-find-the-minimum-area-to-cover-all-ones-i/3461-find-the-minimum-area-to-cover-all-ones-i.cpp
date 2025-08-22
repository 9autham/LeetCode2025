class Solution {
public:
    int minimumArea(vector<vector<int>>& nums) {
        int n=nums.size();
        int m=nums[0].size();
        int minrow=n;
        int mincol=m;
        int maxrow=-1;
        int maxcol=-1;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(nums[i][j]==1){
                    minrow=min(minrow,i);
                    mincol=min(mincol,j);
                    maxrow=max(maxrow,i);
                    maxcol=max(maxcol,j);
                }
            }
        }
        if(maxcol==-1){
            return 0;
        }
        int x=maxrow-minrow+1;
        int y=maxcol-mincol+1;
        return x*y;
    }
};