class Solution {
public:
    int numRabbits(vector<int>& answers) {
        vector<int> hash(1001);
        int sum=0;
        for(int ans:answers) {
            if(++hash[ans]==1) sum+=ans+1;
            if(hash[ans]==ans+1) hash[ans]=0;
        }
        return sum;
    }
};