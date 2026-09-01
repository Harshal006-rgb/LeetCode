class Solution {
public:
    int minFlipsMonoIncr(string s) {
        int n = s.size();
        int zerocnt = 0;
        int onecnt = 0;
        for( int i = 0 ; i < n ; i++ ) {
            if( s[i] -'0' == 0 ) zerocnt++;
        }
        int ans = zerocnt;

        for( int i = 0 ; i < n ; i++ ) {
            if( s[i]-'0' == 0 ) zerocnt--;
            else onecnt++;
            ans = min(ans,zerocnt+onecnt);
        }

        return ans;

    }
};