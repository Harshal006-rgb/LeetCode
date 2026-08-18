class Solution {
public:
    int nthUglyNumber(int n) {
        vector<int> dp(n);
        dp[0] = 1;

        int p1 = 0 , p2 = 0 , p3 = 0;

        for( int i = 1 ; i < n ; i++ ) {
            int min1 = dp[p1]*2;
            int min2 = dp[p2]*3;
            int min3 = dp[p3]*5;

            int mini = min({min1,min2,min3});
            dp[i] = mini;

            if( mini == min1 ) p1++;
            if( mini == min2 ) p2++;
            if( mini == min3 ) p3++;
        }

        return dp[n-1];
    }
};