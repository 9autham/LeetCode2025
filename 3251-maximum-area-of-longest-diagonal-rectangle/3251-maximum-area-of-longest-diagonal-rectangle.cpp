class Solution {
public:
    int areaOfMaxDiagonal(vector<vector<int>>& nums) {
        int n=nums.size();
        float ans=0;
        int area=0;
        for(int i=0;i<n;i++){
            int xx=nums[i][0];
            int yy=nums[i][1];
            float dd=sqrt(xx*xx*1.0+yy*yy*1.0);
            cout<<dd<<endl;
            if(ans==dd){
                area=max(area,xx*yy);
            }
            else if(ans<dd){
                ans=dd;
                area=xx*yy;
            }
        }
        return area;
    }
};