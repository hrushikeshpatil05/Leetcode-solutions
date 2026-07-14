class Solution {
public:
    bool canItAll(vector<int>& piles, int k, int h) {
        long long currH = 0;
        for(auto pile: piles) {
            currH += (pile + k - 1)/k;
        }
        if(currH <= h) {
            return true;
        }
        return false;
    }
    int minEatingSpeed(vector<int>& piles, int h) {
        int low = 1;
        int high = *max_element(piles.begin(),piles.end());
        int res = high;
        while(low <= high) {
            int mid = low + (high - low)/2;

            if(canItAll(piles,mid,h)) {
                res = min(res,mid);
                high = mid - 1;
            }
            else {
                low = mid + 1;
            }
        }
        return res;
    }
};