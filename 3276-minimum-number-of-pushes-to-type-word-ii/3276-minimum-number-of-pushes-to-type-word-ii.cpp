class Solution {
public:
    int minimumPushes(string word) {

        vector<int> letters(26,0);
        for( char c : word ) letters[c-'a']++;
        sort(letters.rbegin(),letters.rend());
        
        int ans = 0;
        int multiplier = 0;

        for( int i = 0 ; i < 26 ; i++ ) {
            if( i%8 == 0 ) multiplier++;
            ans += letters[i]*multiplier;
        }

        return ans;

    }
};