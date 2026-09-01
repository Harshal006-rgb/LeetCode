class Solution {
public:
    int n = 0;

    int minFlipsMonoIncr(string s) {
        n = s.size();
        vector<vector<int>> dp(n+1,vector<int>(2,-1));
        return solve( s,0,0,dp );
    }


    int solve(string &s , int i , int prev , vector<vector<int>> &dp ){
        if( i == n ) return 0;

        if( dp[i][prev] != -1 ) return dp[i][prev];

        int flip = INT_MAX;
        int nonflip = INT_MAX;

        if( s[i] == '0' ){
            if( prev == 0 ){
                nonflip = solve(s,i+1,0,dp);
            }
            flip = 1+solve(s,i+1,1,dp);
        }
        else{
            if( prev == 0 ){
                flip = 1+solve(s,i+1,0,dp);
            }
            nonflip = solve(s,i+1,1,dp);
        }

        return dp[i][prev] = min(flip,nonflip);
    }
};