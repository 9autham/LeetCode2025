class Solution {
public:
    long long mostPoints(vector<vector<int>>& questions) {
        int n = questions.size();
        vector<long long> points_from_index(n, -1);
        return f(0, questions, points_from_index);
    }

    long long f(int index, vector<vector<int>>& questions, vector<long long>& points_from_index) {
        if (index >= points_from_index.size()) {
            return 0;
        }
        if (points_from_index[index] != -1) {
            return points_from_index[index];
        }
        long long picked = (long)questions[index][0] + f(index + 1 + questions[index][1], questions, points_from_index);
        long long not_picked = f(index + 1, questions, points_from_index);
        return points_from_index[index] = max(picked, not_picked);
    }
};