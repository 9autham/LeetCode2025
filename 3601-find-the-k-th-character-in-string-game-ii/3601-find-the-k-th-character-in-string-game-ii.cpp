class Solution {
public:
    char kthCharacter(long long k, vector<int>& nums) {
        int n = nums.size();
        long long length = 1; // Start with the initial string "a"
        
        // Calculate the length of the string after all operations
        int alpha=0;
        for (int i = 0; i < n; ++i) {
            if(length<k){
              length *= 2; // Each operation doubles the length
                alpha++;
            }
        }
        int cnt=0;
        
        // Work backwards through the operations to find the k-th character
        for (int idx = min(alpha-1,n - 1); idx >= 0; --idx) {
            long long half_length = length / 2; // Length of the first half
            
            if (k > half_length) {
                // If k is in the second half
                k -= half_length; // Adjust k to find the corresponding position in the first half
                if (nums[idx] == 1) {
                    // If the operation is type 1, we move to the previous character
                    // This means we are looking for the character in the first half
                    cnt++;// Move to the previous character
                }
            }
            // Halve the length for the next operation
            length = half_length;
        }

        // If we end up with k = 1, the character is 'a'
        // Otherwise, the character corresponds to 'a' + (k - 1)
        return 'a' + (cnt) % 26; // Modulo 26 to wrap around the alphabet
    }
};