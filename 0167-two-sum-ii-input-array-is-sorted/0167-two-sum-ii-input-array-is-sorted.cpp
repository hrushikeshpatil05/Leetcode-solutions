class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        int n = numbers.size();

        int left = 0, right = n-1;

        int sum = numbers[left] + numbers[right];

        while(left<right) {

            sum = numbers[left] + numbers[right];
            
            if(sum == target) {
                return {left+1,right+1};
            }

            if(sum > target) {
                right--;
            }
            else {
                left++;
            }
        }
        return {-1,-1};
    }
};