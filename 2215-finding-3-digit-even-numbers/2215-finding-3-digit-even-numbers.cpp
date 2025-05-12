class Solution {
public:
    vector<int> findEvenNumbers(vector<int>& digits) {
        unordered_map<int,int> mp;
        vector<int> ans;
        for(int i=0;i<digits.size();i++){
            mp[digits[i]]++;
        }

        for(int j=100;j<1000;j++){
            int i = j;
            int a = i%10;
            if(a%2!=0) continue;
            i/=10;
            int b = i%10;
            i/=10;
            int c = i%10;
            i/=10;

            if(mp[a]!=0){
                mp[a]--;
            }else{
                continue;
            }
            if(mp[b]!=0){
                mp[b]--;
            }else{
                mp[a]++;
                continue;
            }
            if(mp[c]!=0){
                ans.push_back(j);
            }
            mp[a]++;
            mp[b]++;

        }
       
       sort(ans.begin(),ans.end());

        return ans;
    }
};