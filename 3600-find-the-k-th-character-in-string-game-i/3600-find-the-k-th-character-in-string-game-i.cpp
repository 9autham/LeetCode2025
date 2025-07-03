class Solution {
public:
    string trans(string s){
        string ans="";
        for(int i=0;i<s.size();i++){
            char ch=s[i];
            int num=s[i]-'a';
            num++;
            num=num%26;
            ch=char('a'+num);
            ans.push_back(ch);
        }
        return ans;
    }
    char kthCharacter(int k) {
        string s="a";
        while(s.size()<k){
            s=s+trans(s);
        }
        return s[k-1];
    }
};