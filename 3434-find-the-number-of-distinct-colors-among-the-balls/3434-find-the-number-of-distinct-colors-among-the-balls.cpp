class Solution {
public:
    vector<int> queryResults(int limit, vector<vector<int>>& queries) {
        int n = queries.size();
        vector<int> ans;
        unordered_map<int,int> idx,color;
        for( int i = 0 ; i < n ; i++ ) {
            int num = queries[i][0];
            int col = queries[i][1];    
            if(!idx[num] ){
                color[col]++;
                idx[num] = col;
            }
            else if (idx[num] != col){
                color[idx[num]]--;
                if( color[idx[num]] == 0 ) color.erase(idx[num]);
                color[col]++;
                idx[num] = col;
            }
            ans.push_back(color.size());
        }
        return ans;
    }
};