#define ll long long
class Solution {
public:
    bool f(int mh, vector<int>& nums, ll mid) {
        int n = nums.size();
        ll ans = 0;
        for (int i = 0; i < n; i++) {
            ll c = (2 * mid) / nums[i];
            
            // Find integer root
            ll root = (-1 + (ll)sqrt(1 + 4 * c)) / 2;
            
            ans += root;
            
            // If at any point `ans` exceeds or equals `mh`, we can stop early
            if (ans >= mh) return true;
        }
        return ans >= mh;
    }

    long long minNumberOfSeconds(int mh, vector<int>& nums) {
        ll l = 0;
        ll h = 1e18;
        ll ans = h;
        
        while (l <= h) {
            ll mid = l + (h - l) / 2;
            
            if (f(mh, nums, mid)) {
                ans = mid;
                h = mid - 1;
            } else {
                l = mid + 1;
            }
        }
        return ans;
    }
};
