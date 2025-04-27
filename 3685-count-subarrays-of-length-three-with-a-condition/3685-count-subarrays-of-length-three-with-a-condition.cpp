class Solution {
public:
    int countSubarrays(vector<int>& arr) {
        int n=arr.size();
        int c=0;
        for(int i=0;i<n-2;i++)
        {
            if(arr[i]+arr[i+2]==arr[i+1]/2.0)
                c++;
        }
        return c;
    }
};