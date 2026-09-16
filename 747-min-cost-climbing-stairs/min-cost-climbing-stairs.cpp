class Solution {
public:
    int Ways(int n,vector<int>cost,vector<int>&dp)
    {
        if(n<=1)
        {
            return 0;
        }
        if(dp[n]!=-1)
        {
            return dp[n];
        }
        return dp[n]=min(cost[n-1]+Ways(n-1,cost,dp),cost[n-2]+Ways(n-2,cost,dp));
    }
    int minCostClimbingStairs(vector<int>& cost) {
        int n=cost.size();
        vector<int>dp(n+1,-1);
        return Ways(n,cost,dp);
    }
};