class Solution {
public:
    int zigZagArrays(int n, int l, int r) {
        if (n == 1) return r - l + 1;
        
        int M = r - l;
        int mod = 1e9 + 7;
        
        // prevRow represents the number of valid arrays at step (idx - 1)
        // Step 1: Every starting number has exactly 1 way to be chosen.
        vector<int> prevRow(M + 1, 1);
        
        // Loop through the remaining (N - 1) steps
        for (int i = 1; i < n; i++) {
            vector<int> currRow(M + 1, 0);
            long long runningSum = 0;
            
            // If i is odd, it's an UP move (assuming Pattern A: Up-Down-Up)
            if (i % 2 != 0) {
                // Prefix sum from left to right
                for (int j = 0; j <= M; j++) {
                    currRow[j] = runningSum;
                    runningSum = (runningSum + prevRow[j]) % mod;
                }
            } 
            // If i is even, it's a DOWN move
            else {
                // Suffix sum from right to left
                for (int j = M; j >= 0; j--) {
                    currRow[j] = runningSum;
                    runningSum = (runningSum + prevRow[j]) % mod;
                }
            }
            
            // Move down the DP tree
            prevRow = currRow; 
        }
        
        // Sum up all valid sequences for Pattern A
        long long ans = 0;
        for (int i = 0; i <= M; i++) {
            ans = (ans + prevRow[i]) % mod;
        }
        
        // Multiply by 2 to account for Pattern B (Down-Up-Down)
        return (ans * 2) % mod;
    }
};