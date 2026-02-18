class Solution {
public:
    bool hasAlternatingBits(int n) {
        int nsb=0;
        for(int i=0;i<32;i++){
            if(n&(1<<i))
                nsb=i;
        }
        for(int i=0;i<nsb;i++){
            int a=n&(1<<i);
            int b=n&(1<<(i+1));
            cout<<a<<" "<<b<<endl;
            if(a==b)
                return false;
            if(a!=0 and b!=0)
                return false;
        }
        return true;
    }
};