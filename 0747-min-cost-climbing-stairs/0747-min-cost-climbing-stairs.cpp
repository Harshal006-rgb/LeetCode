class Solution {
public:
    int minCostClimbingStairs(vector<int> &cost)
    {
        int n = cost.size();
        vector<int> dp(n, -1);
        dp[0] = cost[0];
        dp[1] = cost[1];

        for (int i = 2; i < n; i++)
        {
            int onestep = rec(i - 1, cost, dp);
            int twostep = rec(i - 2, cost, dp);
            dp[i] = min(twostep, onestep) + cost[i];
        }

        return min(dp[n-1],dp[n-2]);
    }

    int rec( int i , vector<int>& cost , vector<int> & dp){
        if( i <= 1 ) return cost[i];
        if( dp[i] != -1 ) return dp[i];
        int onestep = rec(i-1,cost,dp);
        int twostep = rec(i-2,cost,dp);
        return dp[i] = min(twostep,onestep) + cost[i];
    }
};