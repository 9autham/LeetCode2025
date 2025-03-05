class Solution {
public:
    long long coloredCells(int n) {
        long long int cnt=0;
        if(n==1)
            return 1;
        int x=1;
        for(int i=0;i<n;i++){
            if(i==n-1){
                cnt+=x;
            }
            else{
                cnt+=2*x;
            }
            x=x+2;
        }
        return cnt;
    }
};