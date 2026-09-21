class Solution {
public:
    vector<long long> resultArray(vector<int>& nums, int k) {
        vector<long long> ans(k, 0);
        vector<long long> dp(k, 0);

        for(int num : nums)
        {
            int val = num % k;

            vector<long long> next(k, 0);

            next[val] = 1;

            for(int r = 0; r < k; r++)
            {
                int nr = (r * val) % k;
                next[nr] += dp[r];
            }

            for(int r = 0; r < k; r++)
            {
                ans[r] += next[r];
            }

            dp = next;
        }

        return ans;
    }
};