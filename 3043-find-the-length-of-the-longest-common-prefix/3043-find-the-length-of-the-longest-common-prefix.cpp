class Solution {
public:
    int longestCommonPrefix(vector<int>& arr1, vector<int>& arr2) {
        unordered_set<string> prefixes;
        int n1 = arr1.size(), n2 = arr2.size();
        for (int i = 0; i < n1; i++) {
            string value = to_string(arr1[i]);
            string prefix = "";
            for (int k = 0; k < value.size(); k++) {
                prefix.push_back(value[k]);
                prefixes.insert(prefix);
            }
        }

        int result = 0;
        for (int i = 0; i < n2; i++) {
            string value = to_string(arr2[i]);
            string prefix = "";
            for (int k = 0; k < value.size(); k++) {
                prefix.push_back(value[k]);
                if (prefixes.find(prefix) == prefixes.end())
                    break;
                result = max(result, k + 1);
            }
        }
        return result;
    }
};