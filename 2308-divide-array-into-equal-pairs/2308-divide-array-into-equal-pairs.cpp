class Solution {
public:
    bool divideArray(vector<int>& v){
        sort(v.begin(),v.end());
        for(int i=0;i<v.size()-1;i++){
            if(v[i]!=v[i+1])
                return false;
            i++;
        }
        return true;
    }
};