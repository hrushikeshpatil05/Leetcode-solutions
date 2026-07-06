class Solution {
public:
    int sumSubarrayMins(vector<int>& arr) {
        int mod = 1e9 + 7;
        int n = arr.size();
        int ans = 0;
        stack<int>st;

        for(int i=0;i<=n;i++) {
            while(!st.empty() && (i == n || arr[i] < arr[st.top()])) {
                int mid = st.top();
                st.pop();

                int rightB = i;

                int leftB = st.empty() ? -1 : st.top();

                int l = mid - leftB;
                int r = rightB - mid;

                long long temp = (l*r)%mod;
                long long comb = (temp*arr[mid])%mod;

                ans = (ans + comb)%mod;
            }
            st.push(i);
        }

        return ans;
    }
};