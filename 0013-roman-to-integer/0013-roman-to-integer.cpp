class Solution {
public:
    int romanToInt(string s) {
        map<char,int> mp;
        mp['I'] = 1;
        mp['V'] = 5;
        mp['X'] = 10;
        mp['L'] = 50;
        mp['C'] = 100;
        mp['D'] = 500;
        mp['M'] = 1000;
        reverse(s.begin(),s.end());
        int maxi = 0;
        int ans = 0;

        for( char c:s){
            if( mp[c] < maxi ){
                ans-=mp[c];
            }
            else{
                ans+=mp[c];
            }
            maxi = max(mp[c],maxi);
        }

        return ans;


        
    }
};