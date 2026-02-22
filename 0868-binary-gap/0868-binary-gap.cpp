class Solution {
public:
    int binaryGap(int n) {
        int nsb=-1;
        for(int i=0;i<32;i++){
            if(n&(1<<i)){
                nsb=i;
                break;
            }
        }
        if(nsb==-1)
            return 0;
        int ans=0;
        int pos=nsb;
        for(int i=nsb+1;i<32;i++){
            if(n&(1<<i)){
                ans=max(ans,(i-pos));
                pos=i;
            }
        }
        return ans;
    }
};