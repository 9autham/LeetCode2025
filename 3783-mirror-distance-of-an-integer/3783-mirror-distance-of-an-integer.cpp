class Solution {
public:
    int reverse(int n) {
        int num=0;
        while(n){
            num=num*10+n%10;
            n=n/10;
        }
        return num;
    }
    int mirrorDistance(int n) {
        return abs(n-reverse(n));
    }
};