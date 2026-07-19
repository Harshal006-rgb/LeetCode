class Solution {
public:

    int repeatedStringMatch(string a, string b){
        int n = a.size();
        int m = b.size();
        int cnt = m/n;

        string na = "";

        int i = 0;
        while(i < cnt){
            na += a;
            i++;
        }

        if(strStr(na,b)) return cnt;
        na += a;
        if(strStr(na,b)) return cnt+1;
        na += a;
        if(strStr(na,b)) return cnt+2;
        return -1;
    }

    bool strStr(string haystack, string needle) {
        int n = haystack.size();
        int m = needle.size();

        int i = 0;
        int j = 0;
        vector<int> lps = getlps(needle);

        while(i<n){
            if( haystack[i] == needle[j]){
                i++; j++;
            }

            if( j == m ){
                return true;
            }
            else if ( i<n && haystack[i] != needle[j]) {
                if(j!=0){
                    j = lps[j-1];
                }
                else i++;
            }

        }

        return false;
    }
    
    vector<int> getlps( string s ){
        int n = s.size();
        vector<int> lps(n);
        lps[0] = 0;
        int i = 1;
        int len = 0;

        while(i<n){
            if( s[i] == s[len]){
                len++;
                lps[i] = len;
                i++;
            }
            else{
                if(len != 0){
                    len = lps[len-1];
                }
                else{
                    lps[i] = 0;
                    i++;
                }
            }
        }
        return lps;
    }
};