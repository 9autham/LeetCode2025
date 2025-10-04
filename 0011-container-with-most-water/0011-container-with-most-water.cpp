class Solution {
public:
    int maxArea(vector<int>& height) {
        int f=0;
        int l=height.size()-1;
        int ans=0;
        while(f<=l){
            ans=max(ans,min(height[f],height[l])*(l-f));
            if(height[f]>height[l])
                l--;
            else
                f++;
        }
        return ans;
    }
};