class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        string pre = strs[0];

        for( int i = 1 ; i< strs.size() ; i++ ){
            string s;
            for( int j = 0 ; j < min(strs[i].size() , pre.size()) ;j++){
                if(pre[j] == strs[i][j]){
                    s+=pre[j];
                }
                else{
                    break;
                }
            }
            pre = s;
            
        }

        return pre;
        
    }
};