class Solution {
public:
    string makestring(vector<pair<char, int>>& vt){
        string answer;
        for(auto& it: vt){
            answer += (char)(it.second + 48);
            answer += it.first;
        }
        return answer;
    
    }
    string generatefreq(string s){
        vector<pair<char,int>> frq;
        int n = s.size();
        char temp = s[0];
        int fr = 1;
        for(int i = 1; i < n; i++){
            if(s[i] != s[i-1]){
                frq.push_back({s[i-1] , fr});
                fr = 1;
            }
            else
                fr++;
        }

        frq.push_back({s[n-1], fr});

        // for(auto& it: frq)
        //     cout<<it.first<<" "<<it.second;
        
        string ans = makestring(frq);

        cout<<ans<<" ";
        return ans;
    }
    string countAndSay(int n) {
        string ans;
        ans += (char)(49);
        if(n == 1 ){
            return ans;
        }
        int count = 1;
        while(count < n){
            cout<<ans<<" ";
            ans = generatefreq(ans);
            count++;
        }
       return ans;
    }
};