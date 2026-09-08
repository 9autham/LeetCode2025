class Solution {
public:
    int countCommas(int n) {
        int cnt = n-1000+1;
        return cnt>=0 ? cnt : 0;
    }
};