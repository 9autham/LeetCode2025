class Solution {
public:
    int f(vector<int>b){
        sort(b.begin(),b.end());
        int maxi=1;
        int cnt=0;
        int xx=b[0];
        for(int i=0;i<b.size();i++){
            cout<<i<<" "<<cnt<<endl;
            if(xx==b[i]){
                cnt++;
                xx++;
            }
            else{
                cnt=1;
                xx=b[i]+1;
            }
            maxi=max(maxi,cnt);
        }
        return maxi+1;
    }
    int maximizeSquareHoleArea(int n, int m, vector<int>& h, vector<int>& v) {
        int x=f(v);
        int y=f(h);
        int xy=min(x,y);
        // cout<<y<<" "<<x<<endl;
        return pow(xy,2);
        // return min(f(v),f(h))*min(f(v),f(h));
    }
};