class Solution {
public:
    long long putMarbles(vector<int>& weights, int k) {
        int n = weights.size();
        vector<int> diff(n-1);

        for(int i = 1; i<weights.size(); i++){
            long long a = weights[i]+weights[i-1];
            diff[i-1] = a;
        }

        sort(diff.begin(),diff.end());

        long long minisum = 0;
        long long maxisum = 0;

        for(int i = 0; i<k-1; i++){
            minisum += diff[i];
        } 
        long long m = diff.size();
        for(int i = m-1; i>(m-k); i--){
            maxisum += diff[i];
        }
        cout<<minisum<<" "<<maxisum<<endl;

        return maxisum-minisum;

    }
};