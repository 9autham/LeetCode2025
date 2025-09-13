class Solution {
public:
    int maxFreqSum(string s) {
        unordered_map<char, int> freq;
        int con = 0, vow = 0;
        for (char c : s) freq[c]++;
        for (auto& [ch, count] : freq) {
            if (std::string("aeiou").find(ch) != std::string::npos)
                vow = max(vow, count);
            else
                con = max(con, count);
        }
        return con + vow;
    }
};