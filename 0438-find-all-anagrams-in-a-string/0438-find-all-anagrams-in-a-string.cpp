class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        int n = s.size();
        int m = p.size();
        unordered_map<char,int> mp;
        vector<int> ans;

        int i = 0 , j = 0;

        for( char c : p ) mp[c]++;

        for( j = 0 ; j < m ; j++ ){
            mp[s[j]]--;
            if(mp[s[j]] == 0 ) mp.erase(s[j]);
        }


        if( mp.size() == 0 ) ans.push_back(i);

        
        while(j<n){


            mp[s[i]]++;
            if(mp[s[i]] == 0 ) mp.erase(s[i]);
            i++;
            mp[s[j]]--;
            if(mp[s[j]] == 0 ) mp.erase(s[j]);
            if( mp.size() == 0 ) ans.push_back(i);
            j++;


        }

        return ans;
    }
};