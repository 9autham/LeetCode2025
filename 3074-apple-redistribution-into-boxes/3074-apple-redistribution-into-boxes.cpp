class Solution {
public:
    int minimumBoxes(vector<int>& nums, vector<int>& c) {
        int n=nums.size();
        int m=c.size();
        int sum=accumulate(nums.begin(),nums.end(),0);
        sort(c.begin(),c.end());
        if(sum==0)return 0;
        int cnt=0;
        for(int i=m-1;i>=0;i--){
            sum=sum-c[i];
            cout<<sum<<endl;
            cnt++;
            if(sum<=0)return cnt;
        }
        cout<<"YES\n";
        return m;
    }
};