class Solution {
public:
    vector<string> twoEditWords(vector<string>& q, vector<string>& d) {
        vector<string>ans;
        map<string,int>ms;
        for(int i=0;i<q.size();i++){
            for(int j=0;j<d.size();j++){
                cout<<q[i]<<" "<<d[j]<<endl;
                int cnt=0;
                for(int k=0;k<d[j].size();k++){
                    if(d[j][k]!=q[i][k]){
                        cnt++;
                    }
                }
                    if(cnt<=2){
                        ms[q[i]]++;
                    }
            }
        }
        for(int i=0;i<q.size();i++){
            if(ms[q[i]])
                ans.push_back(q[i]);
        }
        return ans;
    }
};