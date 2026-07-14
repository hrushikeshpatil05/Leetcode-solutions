class Solution {
public:
    bool canShip(vector<int>& weights, int days, int capacity) {
        int currLoad = 0;
        int daysNeeded = 1; 

        for(auto weight: weights) {
            if(currLoad + weight > capacity) {
                daysNeeded++;
                currLoad = weight;

                if(daysNeeded > days) {
                    return false;
                }
            }
            else {
                currLoad += weight;
            }
        }
        return true;
    }
    int shipWithinDays(vector<int>& weights, int days) {
        int n = weights.size();

        int low = *max_element(weights.begin(),weights.end());
        int high = accumulate(weights.begin(),weights.end(),0);

        int ans = high;

        while(low <= high) {
            int mid = low + (high - low)/2;

            if(canShip(weights,days,mid)) {
                ans = min(ans,mid);
                high = mid - 1;
            }
            else {
                low = mid + 1;
            }
        }
        return ans;
    }
};