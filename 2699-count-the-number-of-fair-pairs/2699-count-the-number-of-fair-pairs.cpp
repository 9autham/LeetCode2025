class Solution {
public:
    int lowerbond(vector<int>& nums,int i,int j,int value){
        int ind=lower_bound(nums.begin()+i,nums.begin()+j,value)-(nums.begin());
        return ind;
    }
    long long countFairPairs(vector<int>& nums, int lower, int upper) {
        long long int ans=0;
        int i=0;
        int j=nums.size()-1;
        sort(nums.begin(),nums.end());
        while(i<j){
            long long a=nums[i]*1LL;
            long long b=nums[j]*1LL;
            long long sum=a+b;
            if(sum>upper){
                j--;
            }
            else if(sum<=upper and sum>=lower){
                int x=lowerbond(nums,i,j,lower-nums[i]);
                if(x==i and x+1<=j){
                    x++;  
                }
                if(x==i and x+1<j){
                    i++;
                    continue;
                }
                cout<<i<<" "<<j<<" "<<nums[i]<<" "<<x<<endl;
                ans=ans+(j-x+1);
                cout<<j-x+1<<endl;
                i++;
            }
            else if(sum<lower){
                i++;
            }
        }
        return ans;
    }
};