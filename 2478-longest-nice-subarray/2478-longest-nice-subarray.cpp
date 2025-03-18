class Solution {
public:
    int longestNiceSubarray(vector<int>& nums) {
        int left = 0;
        int right = 1;
        int max_size = 0;
        if(nums.size() == 1) return 1;
        if(nums.size() == 0) return 0;
        while(right < nums.size()){
            bool isNice = true;
            for(int i = left; i<right; i++){
                int ans = nums[i] & nums[right];
                if(ans != 0){
                    isNice = false;
                    break;
                }
            }
            
            if(isNice){
                right++;
                max_size = max(right-left, max_size);
            }
            else{
                left++;
            }
        }

        
        return max_size;
    }
};