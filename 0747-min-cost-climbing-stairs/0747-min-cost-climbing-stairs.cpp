class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        int n = cost.size();
        vector<int> dp(n,-1);
        return min(rec(n-1,cost,dp),rec(n-2,cost,dp));
    }

    int rec( int i , vector<int>& cost , vector<int> & dp){
        if( i <= 1 ) return cost[i];
        if( dp[i] != -1 ) return dp[i];
        int onestep = rec(i-1,cost,dp);
        int twostep = rec(i-2,cost,dp);
        return dp[i] = min(twostep,onestep) + cost[i];
    }
};