class Solution {
public:
    int mincostTickets(vector<int>& days, vector<int>& costs) {
        int n = days.size();
        int m = costs.size();

        vector<int>dp(days.back()+1,0);

        unordered_set<int> travelDays(days.begin(), days.end());

        for(int i=1;i<=days.back();i++) {
            if(travelDays.find(i) == travelDays.end()) {
                dp[i] = dp[i-1];
            }
            else {
                int cost1 = dp[i-1] + costs[0];
                int cost2 = dp[max(0,i-7)] + costs[1];
                int cost3 = dp[max(0,i-30)] + costs[2];

                dp[i] = min({cost1,cost2,cost3});
            }
        }
        return dp[days.back()];
    }
};