class Solution {
public:
    int bitwiseComplement(int n) {
        int nsb=0;
        int ans=0;
        for(int i=0;i<32;i++){
            if(n&(1<<i))
                nsb=i;
        }
        cout<<nsb;
        for(int i=0;i<=nsb;i++){
            if(!(n&(1<<i))){
               ans= ans|(1<<i);
                cout<<"hi";
            }
        }
        return ans;
    }
};