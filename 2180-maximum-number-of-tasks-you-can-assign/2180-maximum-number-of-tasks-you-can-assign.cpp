class Solution {
public:
    bool check(int middle, int pills, multiset<int> &stock, vector<int> &tasks, int &strength) {
        for (int i = middle - 1; i >= 0; --i) {
            if (auto worker = prev(stock.end()); *worker >= tasks[i]) {
                stock.erase(worker);
            } else {
                if (!pills) return false;
                auto weakestPossible = stock.lower_bound(tasks[i] - strength);
                if (weakestPossible == stock.end()) return false;
                stock.erase(weakestPossible);
                --pills;
            }
        }
        return true;
    }
    
    int maxTaskAssign(vector<int>& tasks, vector<int>& workers, int pills, int strength) {
        int n = tasks.size(), m = workers.size();
        sort(tasks.begin(), tasks.end());
        sort(workers.begin(), workers.end());
        int left = 1, right = min(n, m), output = 0;
        while (left <= right) {
            int middle = left + ((right - left) >> 1);
            multiset<int> stock;
            for (int i = m - middle;i < m; ++i) stock.insert(workers[i]);
            if (check(middle, pills, stock, tasks, strength)) {
                output = middle;
                left = middle + 1;
            } else right = middle - 1;
        }
        return output;
    }
};