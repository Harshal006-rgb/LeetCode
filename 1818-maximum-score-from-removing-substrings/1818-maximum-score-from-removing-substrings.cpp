class Solution {
public:
    int maximumGain(string s, int x, int y) {
        char c1 = 'a',c2 = 'b';
        
        if(y>x) {
            swap(x,y);
            swap(c1,c2);
        }
        
        int n = s.size();
        int ans = 0;
        
        string s1  = "";
        for( char ch : s ) {
            if( !s1.empty() && ch == c2 && s1.back() == c1 ){
                s1.pop_back();
                ans += x;
            }
            else s1.push_back(ch);
        }

        string s2  = "";
        for( char ch : s1 ) {
            if( !s2.empty() && ch == c1 && s2.back() == c2 ){
                s2.pop_back();
                ans += y;
            }
            else s2.push_back(ch);
        }

        return ans;

    }
};