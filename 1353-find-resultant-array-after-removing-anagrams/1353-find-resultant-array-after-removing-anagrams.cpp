class Solution {
    static constexpr int MAX_SIZE = 10;
public:
    vector<string> removeAnagrams(vector<string>& words) {
        int ri = 0;
        string prev = words[0];
        sort(prev.begin(), prev.end());

        for (int i = 1; i < words.size(); ++i) {
            string curr = words[i];
            sort(curr.begin(), curr.end());
            if (curr != prev) {
                prev = curr;
                words[++ri] = words[i];
            }
        }

        words.resize(++ri);
        return words;
    }
};