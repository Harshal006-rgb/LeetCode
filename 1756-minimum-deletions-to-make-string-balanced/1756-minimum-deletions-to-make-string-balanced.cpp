class Solution
{
public:
    int minimumDeletions(string s)
    {
        int n = s.size();

        int aright = 0;
        int bleft = 0;
        
        for( int i = 0 ; i < n ; i++ ) {
            aright += ( s[i] == 'a');
        }

        int ans = INT_MAX;
        for( int i = 0 ; i < n ; i++ ) {
            if( s[i] == 'a') aright--;
            ans = min( ans , aright + bleft );
            if( s[i] == 'b' ) bleft++;
        }

        return ans;
    }
};