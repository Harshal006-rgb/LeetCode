class Solution {
public:
    string reverseVowels(string s) {
        int n = s.size();
        int l = 0 , r = n-1;
        unordered_map<char,int> mp;
        mp['a'] = 1;
        mp['e'] = 1;
        mp['i'] = 1;
        mp['o'] = 1;
        mp['u'] = 1;
        mp['A'] = 1;
        mp['E'] = 1;
        mp['I'] = 1;
        mp['O'] = 1;
        mp['U'] = 1;
        
        while(l<=r){
            while(!mp[s[l]] && l<r ) l++;
            while(!mp[s[r]] && l<r ) r--;
            swap(s[l],s[r]);
            l++;r--;
        }

        return s;
    }
};