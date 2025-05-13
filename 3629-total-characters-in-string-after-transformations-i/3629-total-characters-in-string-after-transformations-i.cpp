#define MOD 1000000007
#define ll long long
class Solution {
public:
    int modA(int n, int m) { 
        return ((ll)(n % MOD) + (m % MOD)) % MOD; 
    }
    // void print(vector<ll>&a){for(auto &x: a)cout<<x<<" ";cout<<endl;}

    void tras(vector<ll>& v) {
        int z = v[25];
        for (int i = 24; i >= 0; i--) {
            v[i + 1] = v[i];
        }
        v[0] = z;
        v[1] = v[1] + z;
        v[0] %= MOD;
        v[1] %= MOD;
    }

    int lengthAfterTransformations(string s, int t) {
        vector<ll> v(26, 0);        
        for (auto it : s) {
            v[it - 'a']++;
        }
        while (t--) {
            tras(v);
            // print(v);
        }
        int ans = 0;
        for (auto it : v) {
            ans = modA(ans, it);
        }
        return ans;
    }
};
