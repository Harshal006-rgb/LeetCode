
class Solution {
public:
    string reverseParentheses(string s) {
        int n = s.size();
        stack<int> l;
        string ans;

        for( char ch : s) {
            if(ch == ')') {
                reverse(ans.begin() + l.top(),ans.end());            
                l.pop();
            }
            else if(ch=='(') l.push(ans.size());
            else ans.push_back(ch);
        }

        return ans;
    }
};