class Solution {
public:
    int countKConstraintSubstrings(string s, int k) {
        int n = s.size();
        int ones = 0;
        int zeros = 0;
        int l = 0;

        int substrings = 0;

        for( int r = 0 ; r < n ; r++ ) {
            if( s[r] == '1') ones++;
            else zeros++;

            while( ones > k && zeros > k ){
                if( s[l] == '1' ) ones--;
                else zeros--;
                l++;
            }

            substrings += r-l+1;            
        }

        return substrings;
    }
};