class Solution {
public:
    bool makeEqual(vector<string>& words) {
        int n = words.size();
        unordered_map<char,int> mp;

        for( int i = 0 ; i < n ; i++ ) {
            for( char c : words[i]){
                mp[c]++;
            }
        }

        for( int i = 0 ; i < 26 ; i++ ) {
            if(mp[i +'a'] % n) return false;
        }
        return true;
    }
};