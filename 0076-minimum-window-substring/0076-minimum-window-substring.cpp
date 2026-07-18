class Solution
{
public:
    string minWindow(string s, string t)
    {
        unordered_map<char, int> mp;

        for (char c : t) mp[c]++;
        int cnt = 0;

        int i = 0, j = 0;
        int n = s.size();
        int m = t.size();

        int idx = 0, size = INT_MAX;

        while (j < n){

            if(mp[s[j]] > 0 ) cnt++;
            mp[s[j]]--;

            while (cnt == m){
                if (size > j - i + 1){
                    size = j - i + 1;
                    idx = i;
                }
                mp[s[i]]++;
                if(mp[s[i]]>0) cnt--;
                i++;
            }
            j++;

        }

        if( size == INT_MAX ) return "";

        return s.substr(idx,size);
    }
};