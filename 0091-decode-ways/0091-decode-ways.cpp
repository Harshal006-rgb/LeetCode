class Solution {
public:
    int ans = 0;
    int numDecodings(string s) {
        int n = s.size();
        vector<int> dp(n,-1);
        return rec(0,s,dp);
    }

    int rec( int i , string s , vector<int> &dp){
        if( i == s.size()) return 1;
        if(dp[i]!=-1) return dp[i];
        if( s[i] == '0' ) return 0;

        int ways = rec(i+1,s,dp);

        if( i+1 < s.size() ){
            int num = (s[i]-'0')*10 + (s[i+1]-'0');
            if( num <= 26 ){
                ways += rec(i+2,s,dp);
            }
        }
        return dp[i] = ways;
    }
};