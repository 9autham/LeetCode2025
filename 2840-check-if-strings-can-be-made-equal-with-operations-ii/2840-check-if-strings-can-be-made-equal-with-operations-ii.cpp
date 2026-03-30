class Solution {
public:
    bool checkStrings(string s1, string s2) {
        string x1=s1;
        string x2=s2;
        sort(x1.begin(),x1.end());
        sort(x2.begin(),x2.end());
        if(x1!=x2)return false;
        int n=s1.size();
        map<int,int>m1,m2;
        for(int i=0;i<n;i++){
            if(i%2==0){
                m1[s1[i]]++;
            }
        }
        for(int i=0;i<n;i++){
            if(i%2==0){
                m2[s2[i]]++;
            }
        }
        return m1==m2;
    }
};