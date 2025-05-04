class Solution {
public:
    int numEquivDominoPairs(std::vector<std::vector<int>>& dominoes) {
        std::unordered_map<int, int> ctr;
        int ans = 0;

        for (const auto& domino : dominoes) {
            int a = domino[0];
            int b = domino[1];
            int key = std::min(a, b) * 10 + std::max(a, b);
            ans += ctr[key]; 
            ctr[key]++;
        }

        return ans;
    }
};