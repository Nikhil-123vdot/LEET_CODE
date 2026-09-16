class Solution {
public:

    long long solve(int n, int k,
                    vector<vector<long long>>& dp)
    {
        if(k == 0 || k == n)
            return 1;

        if(k < 0 || k > n)
            return 0;

        if(dp[n][k] != -1)
            return dp[n][k];

        return dp[n][k] =
            (solve(n - 1, k - 1, dp) +
             solve(n - 1, k, dp)) % 1000000007;
    }

    int numberOfSets(int n, int k)
    {
        int N = n + k - 1;
        int R = 2 * k;

        vector<vector<long long>> dp(
            N + 1,
            vector<long long>(R + 1, -1)
        );

        return solve(N, R, dp);
    }
};