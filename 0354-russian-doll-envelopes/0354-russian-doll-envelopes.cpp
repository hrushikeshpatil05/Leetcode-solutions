class Solution {
    static bool comparator(const vector<int>& a, vector<int>& b) {
        if (a[0] != b[0]) {
            return a[0] < b[0];
        }
        return a[1] > b[1];
    }

public:
    int n;

    // int solve(int i,int prev,vector<vector<int>>&
    // envelopes,vector<vector<int>>& dp) {
    //     if(i >= n) {
    //         return 0;
    //     }

    //     if(dp[i][prev+1] != -1) {
    //         return dp[i][prev+1];
    //     }

    //     int nottake = solve(i+1,prev,envelopes,dp);

    //     int take = 0;

    //     if(prev == -1 || envelopes[i][0] > envelopes[prev][0] &&
    //     envelopes[i][1] > envelopes[prev][1]) {
    //         take = 1 + solve(i+1,i,envelopes,dp);
    //     }
    //     return dp[i][prev+1] = max(take,nottake);
    // }
    int maxEnvelopes(vector<vector<int>>& envelopes) {
        sort(envelopes.begin(), envelopes.end(), comparator);
        n = envelopes.size();
        // vector<vector<int>>dp(n+1,vector<int>(n+1,-1));
        // return solve(0,-1,envelopes,dp);

        vector<int> heights;
        for (auto h : envelopes) {
            heights.push_back(h[1]);
        }

        vector<int> tails;

        for (auto h : heights) {
            auto it = lower_bound(tails.begin(), tails.end(), h);

            if (it == tails.end()) {
                tails.push_back(h);
            }

            else {
                *it = h;
            }
        }
        return tails.size();
    }
};