class Solution {
private:
    string removeVowels(string s) {
        for (int i = 0; i < s.length(); i++) {
            if (string("aeiou").find(s[i]) != string::npos) {
                s[i] = '*';
            }
        }
        return s;
    }
    
    string toLowerCase(string s) {
        for (char& c : s) {
            c = tolower(c);
        }
        return s;
    }

public:
    vector<string> spellchecker(vector<string>& wordlist, vector<string>& queries) {
        unordered_set<string> wordSet(wordlist.begin(), wordlist.end());
        
        unordered_map<string, string> lowercaseMap;
        for (const string& word : wordlist) {
            string lowercaseWord = toLowerCase(word);
            if (lowercaseMap.find(lowercaseWord) == lowercaseMap.end()) {
                lowercaseMap[lowercaseWord] = word;
            }
        }
        
        unordered_map<string, string> vowelsMap;
        for (const string& word : wordlist) {
            string vowelWord = removeVowels(toLowerCase(word));
            if (vowelsMap.find(vowelWord) == vowelsMap.end()) {
                vowelsMap[vowelWord] = word;
            }
        }
        
        vector<string> result;
        for (const string& query : queries) {
            if (wordSet.count(query)) {
                result.push_back(query);
            } else {
                string lowercaseWord = toLowerCase(query);
                if (lowercaseMap.count(lowercaseWord)) {
                    result.push_back(lowercaseMap[lowercaseWord]);
                } else {
                    string vowelWord = removeVowels(lowercaseWord);
                    if (vowelsMap.count(vowelWord)) {
                        result.push_back(vowelsMap[vowelWord]);
                    } else {
                        result.push_back("");
                    }
                }
            }
        }
        return result;
    }
};