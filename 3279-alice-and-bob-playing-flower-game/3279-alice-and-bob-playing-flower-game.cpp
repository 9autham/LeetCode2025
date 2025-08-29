#define ll long long 
class Solution {
public:
    long long flowerGame(int n, int m) {
        ll nodd=n/2+(n%2);
        ll neven=n-nodd;
        ll modd=m/2+(m%2);
        ll meven=m-modd;
        ll ans=nodd*meven+modd*neven;
        return ans;
    }
};