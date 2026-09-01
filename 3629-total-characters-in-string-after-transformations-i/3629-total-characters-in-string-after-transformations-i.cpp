class Solution {
public:
    int lengthAfterTransformations(string s, int t) {
        int n = s.size();
        vector<int> freq(26,0);

        for( int i = 0 ; i < n ; i++ ) {
            freq[s[i]-'a']++;
        }

        int mod = 1e9+7;

        for( int j = 0 ; j < t ; j++ ) {

            vector<int> newfreq(26,0);

            for( int i = 0 ; i < 25 ; i++ ) {
                newfreq[i+1] = freq[i];                
            }

            newfreq[0] = ( freq[25] )%mod;
            newfreq[1] = ( newfreq[1] + freq[25] )%mod;

            freq = newfreq;
        }

        int size = 0;

        for( int i = 0 ; i < 26 ; i++ ) {
            size = (size + freq[i] )%mod;            
        }
        return size;
    }
};