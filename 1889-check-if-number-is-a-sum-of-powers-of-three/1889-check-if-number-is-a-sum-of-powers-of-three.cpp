class Solution {
public:
    bool checkPowersOfThree(int n) {
        while(n>0){
           int rem = n%3;
           n = n/3;
           if(rem == 0 || rem == 1) continue;
           else return false;
        }
        return true;
    }
};