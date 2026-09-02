class Solution {
public:
    vector<int> partitionLabels(string s) {
        int n = s.size();
        vector<int> last_pos(26,-1);

        for( int i = 0 ; i < n ; i++ ) {
            last_pos[s[i]-'a'] = i;
        }

        int start = 0;
        int end = 0;
        vector<int> result;

        for( int i = 0 ; i < n ; i++ ) {
            end = max(end,last_pos[s[i]-'a']);
            if( i == end ){
                result.push_back(i-start+1);
                start = i+1;
            }
        }
        
        return result;
    }
};