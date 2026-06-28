class Solution {
public:
    // int solve(vector<int>& nums,int k) {
    //     int n = nums.size();

    //     int left = 0;
    //     int ctOfArrays = 0;
    //     int oddCt = 0;

    //     for(int right = 0; right < n; right++) {
    //         if(nums[right]%2 != 0) {
    //             oddCt++;
    //         }

    //         while(oddCt > k) {
    //             if(nums[left]%2 != 0) {
    //                 oddCt--;
    //             }
    //             left++;
    //         }

    //         ctOfArrays += (right - left + 1);
    //     }
    //     return ctOfArrays;
    // }
    int numberOfSubarrays(vector<int>& nums, int k) {
        
        int n = nums.size();

        // unordered_map<int,int>mp;
        // mp[0] = 1;
        int currCt = 0;
        int ans = 0;
        int left = 0;
        int initialCt = 0;
        for(int i=0;i<n;i++) {
            if(nums[i]%2 != 0) {
                currCt++;
            }

            if(currCt == k) {
                initialCt = 0;

                while(currCt == k) {
                    currCt -= nums[left]%2;
                    left++;
                    initialCt++;
                }
            }
            ans += initialCt;
            
        }
        return ans;

    }
};