class Solution {
public:
    bool isValid(string s) {
        stack<char> st;
        map<char,char> mp;
        mp[')'] = '(';
        mp['}'] = '{';
        mp[']'] = '[';

        int n = s.size();
        for( int i = 0 ; i < n ; i++ ) {

            if( s[i] == ')' || s[i] == '}' || s[i] == ']' ){
                if( !st.empty() && mp[s[i]] == st.top() ){
                    st.pop();
                }
                else return false;
            }
            else{
                st.push(s[i]);
            }
            
            
        }

        return st.empty();
    }
};