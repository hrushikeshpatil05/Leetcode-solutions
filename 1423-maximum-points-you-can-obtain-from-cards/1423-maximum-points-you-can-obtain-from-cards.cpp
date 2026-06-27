class Solution {
public:
    int maxScore(vector<int>& cardPoints, int k) {
        int ans = 0;
        int n = cardPoints.size();

        int leftSum = 0, rightSum = 0;

        for(int i=0;i<k;i++) {
            leftSum += cardPoints[i];
        }

        int left = k-1;
        int right = n-1;

        while(left >= 0) {
            ans = max(ans,leftSum + rightSum);

            leftSum -= cardPoints[left];
            rightSum += cardPoints[right];
            left--;
            right--;
        }
        ans = max(ans,leftSum+rightSum);
        return ans;
    }
};