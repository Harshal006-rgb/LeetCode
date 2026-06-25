class Solution {
public:
    string removeStars(string s) {
        int n = s.size();
        string s1;
        stack<int> st;

        for( int i = 0 ; i < n ; i++ ) {
            if(s[i] == '*'){
                st.pop();
                continue;
            }
            st.push(s[i]);
        }

        while(!st.empty()){
            s1.push_back(st.top());
            st.pop();
        }

        reverse(s1.begin(),s1.end());
        return s1;
    }
};