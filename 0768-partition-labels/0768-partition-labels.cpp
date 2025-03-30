class Solution {
public:
    vector<int> partitionLabels(string s) 
{
    unordered_map<char, int> lastIndex;
    for (int i = 0; i < s.length(); i++) {
        lastIndex[s[i]] = i;
    }

    vector<int> partitions;
    int start = 0, end = 0;

    for (int i = 0; i < s.length(); i++) {
        end = max(end, lastIndex[s[i]]);
        if (i == end) {
            partitions.push_back(end - start + 1);
            start = i + 1;
        }
    }

    return partitions;
}
};