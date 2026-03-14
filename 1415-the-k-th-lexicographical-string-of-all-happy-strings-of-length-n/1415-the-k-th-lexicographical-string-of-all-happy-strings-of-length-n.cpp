class Solution {
public:
    void solveRec(int n, int &k, string &ans, string &current) {
        if (current.size() == n) {
            k--;  
            if (k == 0) ans = current; 
            return;
        }
        for (char ch = 'a'; ch <= 'c'; ch++) {
            if (current.empty() || current.back() != ch) {
                current.push_back(ch);
                solveRec(n, k, ans, current);
                current.pop_back();
                if (k == 0) return;
            }
        }
    }
    string getHappyString(int n, int k) {
        string ans = "";
        string current = "";
        solveRec(n, k, ans, current);
        return ans;
    }
};