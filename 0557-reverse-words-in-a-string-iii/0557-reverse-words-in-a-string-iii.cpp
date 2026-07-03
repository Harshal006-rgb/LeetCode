class Solution {
public:
    string reverseWords(string s) {

        int i = 0;
        int n = s.size();
        int st = 0 , end = 0;

        while(i<n){
            if(!isspace(s[i])){
                st = i;
                while(i<n && !isspace(s[i])) {
                    i++;
                    end = i;
                }
                reverse(s.begin()+st,s.begin()+end);
            } 
            else{
                i++;
            }
        }
        return s;
    }
};