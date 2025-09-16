
class Solution {
public:
    vector<int> replaceNonCoprimes(vector<int>& a) {
        stack<int> st;
        for (int x : a) {
            int cur = x;
            while (!st.empty()) {
                int g = gcd(st.top(), cur);
                if (g == 1) break;
                cur = lcm(cur, st.top());
                st.pop();
            }
            st.push(cur);
        }
        vector<int> ans;
        while (!st.empty()) {
            ans.push_back(st.top());
            st.pop();
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};