class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        unordered_set<string> st;
        int n = s.size();
        vector<int> dp(n,-1);
        for( string str : wordDict ) st.insert(str);
        return rec(0,s,st,dp);
    }

    bool rec( int i , string s , unordered_set<string> &st,vector<int> &dp){
        int n = s.size();
        if( i == n ) return true;
        if( dp[i] != -1 ) return dp[i] == 1;
        if( st.find(s) != st.end()) return true;

        for( int l = 1 ; l < n ; l++ ) {
            string temp = s.substr(i,l);
            if( st.find(temp) != st.end() && rec(i+l,s,st,dp) ){
                dp[i] = 1;
                return true;
            };             
        }
        dp[i] = 0;
        return false;
    }
};