class Solution
{
public:
    int minimumDeletions(string s)
    {
        int n = s.size();
        vector<int> aright(n,0);
        // vector<int> bleft(n,0);
        
        for( int i = n-2 ; i >= 0 ; i-- ) {
            aright[i] = aright[i+1] + (s[i+1] == 'a');
        }

        int bleft = 0;

        int ans = INT_MAX;
        for( int i = 0 ; i < n ; i++ ) {
            ans = min( ans , aright[i] + bleft );
            if( s[i] == 'b' ) bleft++;
        }

        return ans;
    }
};