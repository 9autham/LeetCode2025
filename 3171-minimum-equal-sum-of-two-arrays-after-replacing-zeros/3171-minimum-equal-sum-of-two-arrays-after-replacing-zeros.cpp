#define ll long long
class Solution {
public:
    long long minSum(vector<int>& nums1, vector<int>& nums2) {
        int n=nums1.size();
        int m=nums2.size();
        ll c1=0;
        ll c2=0;
        ll s1=0;
        ll s2=0;
        for(int i=0;i<n;i++){
            if(nums1[i]==0)c1++;
            s1=s1+nums1[i];
        }
        for(int i=0;i<m;i++){
            if(nums2[i]==0)c2++;
            s2=s2+nums2[i];
        }
        cout<<s1<<" "<<s2<<" "<<c1<<" "<<c2<<" "<<abs(s1-s2)<<endl;
        if(c1==0 and c2==0 and s1==s2){
            return s1;
        }
        if(c1==0 and c2==0 and s1!=s2){
            return -1;
        }
        if(s1==s2){
            if(c1!=0 and c2!=0)
            return s1+max(c1,c2);
            return -1;
        }
        if(s1>s2){
            int d=s1-s2;
            if(c1==0){
                if(d<c2){
                    return -1;
                }
                else{
                    return s1+c1;
                }
            }
            if(c2==0){
                return -1;
            }
            int ans=s1+c1;
            int dd=ans-s2;
            if(dd<c2){
                return ans+abs(dd-c2);
            }
            return s1+c1;
        }
        else{
            int d=s2-s1;
            if(c1==0){
                return -1;
            }
            if(c2==0){
                if(d<c1){
                    return -1;
                }
                else{
                    return s2+c2;
                }
            }
            int ans=s2+c2;
            int dd=ans-s1;
            if(dd<c1){
                return ans+abs(dd-c1);
            }
            return s2+c2;
        }
    }
};