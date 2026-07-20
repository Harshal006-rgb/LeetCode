class Solution {
public:
    int equalSubstring(string s, string t, int maxCost) {
        int n = s.size();
        vector<int> num(n,0);
        for( int i = 0 ; i < n ; i++ ){
            num[i] = abs(s[i]-t[i]);
        }
        int l = 0 , r = 0;
        int cost = 0;
        int maxi = 0;

        while(r<n){
            cost += num[r];

            while( cost > maxCost ){
                cost -= num[l];
                l++;
            }

            maxi = max( maxi , r-l+1);
            r++;
        }

        return maxi;
    }
};