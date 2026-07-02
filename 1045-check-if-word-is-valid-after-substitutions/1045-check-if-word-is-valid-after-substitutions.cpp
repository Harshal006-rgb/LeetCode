class Solution {
public:
    bool isValid(string s) {
        int n = s.size();
        
        string s1 = "";
        for( char c : s) {
            if( s1.size() >= 2 && s1[s1.size()-1] == 'b' && s1[s1.size()-2] == 'a' && c == 'c'){
                s1.pop_back();
                s1.pop_back();
            }
            else s1.push_back(c);
        }

        return s1.empty();

    }
};