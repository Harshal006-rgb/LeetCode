class Solution {
public:
    vector<int> decrypt(vector<int>& code, int k) {
        int n = code.size();
        vector<int> ans(n,0);
        if( k == 0 ) return ans;

        if( k > 0 ){
            for( int i = 0 ; i < n ; i++ ) {
                for( int j = i+1 ; j <= i+k ; j++ ) {
                    ans[i] += code[j%n];                    
                }
            }
        }
        else {
            for( int i = 0 ; i < n ; i++ ) {
                for( int j = i-1+n ; j >= i+k+n ; j-- ) {
                    ans[i] += code[j%n];                    
                }
            }
        }
        return ans;

    }
};