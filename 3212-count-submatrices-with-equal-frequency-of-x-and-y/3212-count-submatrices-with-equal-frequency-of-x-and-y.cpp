class Solution {
public:
    int numberOfSubmatrices(vector<vector<char>>& nums) {
        int n=nums.size();
        int m=nums[0].size();
        vector<pair<int,int>>vp(m);
        int xx=0;
        int yy=0;
        int cnt=0;
        for(int i=0;i<m;i++){
            if(nums[0][i] == 'X'){
                xx++;
            }
            if(nums[0][i] == 'Y'){
                yy++;
            }
            vp[i].first=xx;
            vp[i].second=yy;
            if(xx==yy and xx!=0){
                cnt++;
            }
        }
        for(int i=1;i<n;i++){
            cout<<i<<endl;
            int x=0;
            int y=0;
            for(int j=0;j<m;j++){
                if(nums[i][j] == 'X'){
                    x++;
                }
                if(nums[i][j] == 'Y'){
                    y++;
                }
                vp[j].first = x+vp[j].first;
                vp[j].second = y+vp[j].second;
                if(vp[j].first==vp[j].second and vp[j].second!=0){
                    cnt++;
                }
            }
        }
        return cnt;
    }
};