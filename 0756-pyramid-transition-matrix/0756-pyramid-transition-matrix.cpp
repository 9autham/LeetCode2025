class Solution {
public:
    unordered_map<string, vector<char>> allowedPatterns;
    unordered_set<string> memo;

    bool pyramidTransition(string bottom, vector<string>& allowed) {
        for (const string& s : allowed) {
            allowedPatterns[s.substr(0, 2)].push_back(s[2]);
        }
        return solve(bottom);
    }

private:
    bool solve(string row) {
        if (row.length() == 1) return true;
        if (memo.count(row)) return false;

        if (buildNextRow(row, "", 0)) {
            return true;
        }

        memo.insert(row);
        return false;
    }

    bool buildNextRow(const string& currentRow, string nextRow, int idx) {
        if (idx == currentRow.length() - 1) {
            return solve(nextRow);
        }

        string key = currentRow.substr(idx, 2);
        if (allowedPatterns.find(key) == allowedPatterns.end()) {
            return false;
        }

        for (char val : allowedPatterns[key]) {
            nextRow.push_back(val);
            if (buildNextRow(currentRow, nextRow, idx + 1)) {
                return true;
            }
            nextRow.pop_back();
        }

        return false;
    }
};
