struct SegTree {
    int n;                              // Length of the original array
    vector<int> tree;                   // 4*n is sufficient
    const int NEUTRAL = INT_MAX;        // Identity for range minimum

    SegTree(int n = 0) { init(n); }

    void init(int n_) {
        n = n_;
        tree.assign(4 * max(1, n), NEUTRAL);
    }

    // Build: arr is 0-based, covers interval [l, r]
    void build(const vector<int>& arr) {
        init((int)arr.size());
        if (n) build(1, 0, n - 1, arr);
    }

    // Range minimum query over [L, R]
    int query(int L, int R) const {
        if (L > R || n == 0) return NEUTRAL;
        return query(1, 0, n - 1, L, R);
    }

private:
    void build(int node, int l, int r, const vector<int>& arr) {
        if (l == r) {
            tree[node] = arr[l];
            return;
        }
        int m  = l + (r - l) / 2; // mid
        int lc = node * 2;        // left child index
        int rc = lc + 1;          // right child index
        build(lc, l, m, arr);
        build(rc, m + 1, r, arr);
        tree[node] = min(tree[lc], tree[rc]);
    }

    int query(int node, int l, int r, int L, int R) const {
        if (R < l || r < L) return NEUTRAL;       // no overlap
        if (L <= l && r <= R) return tree[node];  // fully covered
        int m  = l + (r - l) / 2; // mid
        int lc = node * 2;        // left child index
        int rc = lc + 1;          // right child index
        int leftMin  = query(lc, l, m, L, R);
        int rightMin = query(rc, m + 1, r, L, R);
        return min(leftMin, rightMin);
    }
};

class Solution {
public:
    int minNumberOperations(vector<int>& target) {
        int n = target.size();
        if (n == 0) return 0;

        // Build: value -> sorted indices
        unordered_map<int, vector<int>> numLoc;
        numLoc.reserve(n * 2);
        for (int i = 0; i < n; ++i) {
            numLoc[target[i]].push_back(i);
        }

        SegTree seg(n);
        seg.build(target);

        function<int(int,int,int)> recur = [&](int left, int right, int curDis) -> int {
            if (left > right) return 0;

            int curMin = seg.query(left, right);
            int ans = curMin - curDis;

            auto& vec = numLoc[curMin];
            auto itL = lower_bound(vec.begin(), vec.end(), left);
            auto itR = upper_bound(vec.begin(), vec.end(), right);

            int last = left;

            for (auto it = itL; it != itR; ++it) {
                int idx = *it;
                ans += recur(last, idx - 1, curMin);
                last = idx + 1;
            }
            ans += recur(last, right, curMin);

            return ans;
        };

        return recur(0, n - 1, 0);
    }
};
