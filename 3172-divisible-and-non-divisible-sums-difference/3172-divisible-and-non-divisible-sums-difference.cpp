class Solution {
public:
    int differenceOfSums(int n, int m) {
        int c=0,d=0;
        for(int i=0;i<=n;i++){
            if(i%m==0){
                c=c+i;
            }
            else{
                d=d+i;
            }
        }
        return d-c;
    }
};