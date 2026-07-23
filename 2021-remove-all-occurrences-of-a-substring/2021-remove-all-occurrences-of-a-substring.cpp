class Solution {
public:
    string removeOccurrences(string s, string part) {
        string ans;
        int n = s.size();
        int m = part.size();

        for( int i = 0 ; i < n ; i++ ) {
            ans+= s[i];
            if( ans.size() >= m && s[i] == part.back() ){
                if(ans.substr(ans.size()-m,m) == part ){
                    for( int i = 0 ; i < m ; i++ ) ans.pop_back();
                }
            }
        }
        return ans;
    }
};