class Solution {
public:
    int longestPalindrome(vector<string>& words) {
        int n = words.size();
        unordered_map<string,int> mp;
        int ans = 0;
        bool same = false;
        
        for( int i = 0 ; i < n ; i++ ) {
            string str = words[i];
            char a = words[i][0] , b = words[i][1];
            string rev = string() + b + a;

            if( a == b ){
                same = true;
                continue;
            }

            if( mp[rev] > 0 ){
                ans += 4;
                mp[rev]--;
            }
            else{
                mp[str]++;
            }
        }

        ans += 2*( same == true );
        return ans;
    }
};