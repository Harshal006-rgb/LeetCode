class Solution {
public:
    int climbStairs(int n) {
        vector<int> dp(n+1,-1);
        return rec(n,dp);
    }

    int rec( int i , vector<int> &dp ){
        if( i == 0 ) return 1;
        if( dp[i] != -1) return dp[i];
        int onestep = rec(i-1,dp);
        int twostep = 0;
        if( i > 1 ) twostep = rec(i-2,dp);
        return dp[i] = onestep + twostep;
    }
};