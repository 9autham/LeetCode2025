class Solution {
public:
    int numberOfSubstrings(string s) {
        int i=0;
        int ans=0;
        unordered_map<char,int>mpp;
        for(int j=0;j<s.size();j++)
        {
            mpp[s[j]]++;
            while(mpp['a']>=1 && mpp['b']>=1 && mpp['c']>=1)
            {
                ans+=s.size()-j;
                mpp[s[i]]--;
                i++;
            }
        }
        return ans;
    }
};