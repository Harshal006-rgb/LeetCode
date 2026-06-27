class Solution {
public:
    string minRemoveToMakeValid(string s) {
        int n = s.size();
        int balanced = 0;
        stack<char> st;
        
        for( int i = 0 ; i < n ; i++ ) {
            if(s[i]=='('){
                balanced++;
            }
            else if(s[i]==')'){
                if(balanced == 0) continue;
                balanced--;
            }
            st.push(s[i]);
        }

        balanced = 0;
        string ans;

        while(!st.empty()){
            int ch = st.top();
            st.pop();
            if(ch == ')') balanced++;
            else if( ch == '(') {
                if(balanced == 0) continue;
                balanced--;
            }
            ans.push_back(ch);
        }

        reverse(ans.begin(),ans.end());
        return ans;
    }
};