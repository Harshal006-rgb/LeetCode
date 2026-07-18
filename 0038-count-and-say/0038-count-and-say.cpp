class Solution {
public:

    string countAndSay(int n) {

        string s = "1";
        int i = 1;

        while(i < n){
            int m = s.size();
            char prev = s[0];
            int cnt = 1;
            string s1 = "";
            
            for( int i = 1 ; i < m ; i++ ){
                if( prev == s[i] ) cnt++;
                else{
                    s1 += to_string(cnt) + prev;
                    prev = s[i];
                    cnt = 1;
                }
            }
            s1 += to_string(cnt) + prev;

            s = s1;
            i++;
        }

        return s;
    }
};