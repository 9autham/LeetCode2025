class Solution {
public:
    int triangleNumber(vector<int>& v) {
        int n=v.size();
        int sum=0;
        sort(v.begin(),v.end());
        for(int i=0;i<n;i++){
            for(int j=i+1;j<n;j++){
                int x=v[i]+v[j];
                int y=abs(v[i]-v[j]);
                auto lp=lower_bound(v.begin()+j+1,v.end(),x);
                auto up=upper_bound(v.begin()+j+1,v.end(),y)-v.begin();
                if(lp-(v.begin()+j+1)==0){
                    continue;
                }
                int lb=lp-v.begin();
                if(up==n){
                    continue;
                }
                if(v[up]==y){
                    up++;
                }
                // if(v[lb]==x and lb<n){
                //     lb--;
                // }
                // if(lb==n){
                //     //all elements can form triangle
                //     lb--;
                // }
                lb--;
                sum+=(lb-up+1);
            }
        }
        return sum;
    }
};