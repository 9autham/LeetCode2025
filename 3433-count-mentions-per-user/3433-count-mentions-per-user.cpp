class Solution {
public:
    vector<int> countMentions(int numberOfUsers, vector<vector<string>>& events) {
        sort(events.begin(), events.end(), [](const vector<string>& a, const vector<string>& b) {
            int ta = stoi(a[1]);
            int tb = stoi(b[1]);
            if (ta != tb) return ta < tb;
            if (a[0] != b[0]) return a[0] == "OFFLINE";  
            return false;
        });
        vector<int> dp(numberOfUsers, 0);  
        vector<int> onl(numberOfUsers, -1); 

        for (auto &e : events) {
            string msgType = e[0];   
            int time = stoi(e[1]);  
            string ppl = e[2];       
            if (msgType == "OFFLINE") {
                int userId = stoi(ppl); 
                onl[userId] = time + 60;  
            } 

            else if (msgType == "MESSAGE") {
                if (ppl == "ALL") {
                    for (int i = 0; i < numberOfUsers; i++) {
                        dp[i]++; 
                    }
                } 
                else if (ppl == "HERE") {
                    for (int i = 0; i < numberOfUsers; i++) {
                        if (onl[i] <= time) {  
                            dp[i]++;  
                        }
                    }
                } 
                else {
                    stringstream ss(ppl);
                    string token;
                    while (ss >> token) {
                        if (token.rfind("id", 0) == 0) {  
                            int userId = stoi(token.substr(2));  
                            
                            dp[userId]++;
                        }
                    }
                }
            }
        }
        
        return dp; 
    }
};