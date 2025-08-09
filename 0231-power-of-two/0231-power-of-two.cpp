class Solution {
public:
    bool isPowerOfTwo(int n) {
        if(n<0)
            return false;
        return n and !(n&(n-1));
    }
};