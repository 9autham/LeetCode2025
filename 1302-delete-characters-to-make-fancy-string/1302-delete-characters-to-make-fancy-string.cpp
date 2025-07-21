class Solution {
public:
    string makeFancyString(string s) {
        string result = "";
        for (int i = 0; i < s.size(); i++) {
            int res_n = result.size();
            if (res_n > 1 && result[res_n - 1] == s[i] && result[res_n - 2] == s[i])
                continue;
            result.push_back(s[i]);
        }
        return result;
    }
};