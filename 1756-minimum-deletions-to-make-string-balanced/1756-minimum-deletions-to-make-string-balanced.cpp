class Solution
{
public:
    int minimumDeletions(string s)
    {
        int n = s.size();
        vector<int> aright(n,0);
        vector<int> bleft(n,0);
        
        for( int i = n-2 ; i >= 0 ; i-- ) {
            aright[i] = aright[i+1] + (s[i+1] == 'a');
        }

        for( int i = 1 ; i < n ; i++ ) {
            bleft[i] = bleft[i-1] + (s[i-1] == 'b');
        }

        int ans = INT_MAX;
        for( int i = 0 ; i < n ; i++ ) {
            ans = min( ans , aright[i] + bleft[i] );
        }

        return ans;
    }
};