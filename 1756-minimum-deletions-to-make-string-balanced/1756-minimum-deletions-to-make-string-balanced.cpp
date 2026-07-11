class Solution {
public:
    int minimumDeletions(string s) {
        int n = s.size();
        stack<int> st;
        int cnt = 0;

        for (char c : s) {
            if ( !st.empty() && c == 'a' && st.top() == 'b') {
                cnt++;
                st.pop();
            } else {
                st.push(c);
            }
        }
        return cnt;
    }
};