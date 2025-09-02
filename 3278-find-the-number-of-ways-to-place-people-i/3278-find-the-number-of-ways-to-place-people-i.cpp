class Solution {
public:
    int numberOfPairs(vector<vector<int>>& nums) {
        int n=nums.size();
        sort(nums.begin(),nums.end());
        int cnt=0;
        for(int i=0;i<n;i++){
            for(int j=i+1;j<n;j++){
                int x0=nums[i][0];
                int y0=nums[i][1];
                int x1=nums[j][0];
                int y1=nums[j][1];
                bool f=true;
                if(y1>y0 and x1!=x0){
                    cout<<"cONT "<<i<<j<<endl;
                    continue;
                }
                if(y1>y0)swap(y1,y0);
                for(int k=0;k<n;k++){
                    if(k==i or k==j)continue;
                    if((nums[k][0]>=x0 and nums[k][0]<=x1) and (nums[k][1]>=y1 and nums[k][1]<=y0)){
                        cout<<"Failing "<<i<<j<<endl;
                        f=false;
                        break;
                    }
                }
                if(f){cnt++; cout<<i<<j<<endl;}
            }
        }
        cout<<"YES\n";
        return cnt;
    }
};