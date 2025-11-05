using PII = pair<int, int>; // {frequency, value}

class Solution {
public:
    vector<long long> findXSum(vector<int>& nums, int k, int x) {
        unordered_map<int, int> mp;
        set<PII> s_x; // Top-x elements
        set<PII> s_o; // Other elements
        int n = nums.size();

        // 1. Initialize the first window
        for (int i = 0; i < k; i++) {
            mp[nums[i]]++;
        }

        vector<PII> v;
        for (auto& it : mp) {
            v.push_back({it.second, it.first}); // {freq, val}
        }

        long long sm = 0;
        vector<long long> ans;
        
        // Sort {freq, val} descending
        sort(v.begin(), v.end(), greater<PII>()); 

        // 2. Populate s_x and s_o from the initial sorted vector
        for (int i = 0; i < (int)v.size(); i++) {
            if (i < x) {
                s_x.insert(v[i]);
                sm += 1LL * v[i].first * v[i].second;
            } else {
                s_o.insert(v[i]);
            }
        }
        ans.push_back(sm);

        // 3. Slide the window
        for (int i = k; i < n; i++) {
            int out_val = nums[i - k];
            int in_val = nums[i];

            if (out_val == in_val) {
                ans.push_back(sm);
                continue;
            } // No change in this case

            // 4. Find and remove the *old* states
            PII old_out = {mp[out_val], out_val};
            PII old_in = {mp[in_val], in_val}; // freq is 0 if not present

            // set::erase(key) returns 1 if an item was removed, 0 otherwise
            if (s_x.erase(old_out)) {
                sm -= 1LL * old_out.first * old_out.second;
            } else {
                s_o.erase(old_out);
            }
            
            if (s_x.erase(old_in)) {
                sm -= 1LL * old_in.first * old_in.second;
            } else {
                s_o.erase(old_in);
            }

            // 5. Update frequencies
            mp[out_val]--;
            mp[in_val]++;

            // 6. Add the *new* states to s_o as a temporary holding area
            PII new_out = {mp[out_val], out_val};
            PII new_in = {mp[in_val], in_val};

            if (new_out.first > 0) s_o.insert(new_out);
            s_o.insert(new_in); // new_in's freq is always >= 1

            // 7. Re-balance the sets
            // First, fill s_x if it's under capacity
            while (s_o.size() && s_x.size() < x) {
                PII best_other = *s_o.rbegin();
                s_o.erase(best_other);
                s_x.insert(best_other);
                sm += 1LL * best_other.first * best_other.second;
            }

            // Second, swap if the best of 'other' is better than worst of 'top-x'
            // *s_o.rbegin() = best of others (highest freq/val)
            // *s_x.begin() = worst of top-x (lowest freq/val)
            while (s_o.size() && s_x.size() && *(s_o.rbegin()) > *(s_x.begin())) {
                PII best_other = *s_o.rbegin();
                PII worst_top = *s_x.begin();

                // Erase from original sets
                s_o.erase(best_other);
                s_x.erase(worst_top);
                
                // Add to new sets (swap)
                s_x.insert(best_other);
                s_o.insert(worst_top);

                // Update sum
                sm += 1LL * best_other.first * best_other.second;
                sm -= 1LL * worst_top.first * worst_top.second;
            }
            
            ans.push_back(sm);
        }
        return ans;
    }
};