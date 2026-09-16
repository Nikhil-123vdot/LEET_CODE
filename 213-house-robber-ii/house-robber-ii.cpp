class Solution {
public:

    int robb(vector<int>& nums) {
        int n = nums.size();

        if(n == 0)
            return 0;

        if(n == 1)
            return nums[0];

        vector<int> dp(n);

        dp[0] = nums[0];
        dp[1] = max(nums[0], nums[1]);

        for(int i = 2; i < n; i++) {
            dp[i] = max(nums[i] + dp[i-2], dp[i-1]);
        }

        return dp[n-1];
    }

    int rob(vector<int>& nums) {
        int n = nums.size();

        if(n == 1)
            return nums[0];

        vector<int> arr1(n-1);
        vector<int> arr2(n-1);

        // Exclude last house
        for(int i = 0; i < n-1; i++) {
            arr1[i] = nums[i];
        }

        // Exclude first house
        for(int i = 1; i < n; i++) {
            arr2[i-1] = nums[i];
        }

        int curr1 = robb(arr1);
        int curr2 = robb(arr2);

        return max(curr1, curr2);
    }
};