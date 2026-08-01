class Solution {
public:
    vector<vector<int>> findWinners(vector<vector<int>>& matches) {
        unordered_map<int,int> win,loss;
        set<int> st1,st2;

        int n = matches.size();

        for( int i = 0 ; i < n ; i++ ) {
            int a = matches[i][0];
            int b = matches[i][1];
            win[a]++;
            loss[b]++;            
        }

        for( int i = 0 ; i < n ; i++ ) {
            int a = matches[i][0];
            int b = matches[i][1];
            if( loss[a] == 0 ) st1.insert(a);
            if( loss[b] == 1 ) st2.insert(b);        
        }

        vector<vector<int>> ans;
        vector<int> winner(st1.begin(),st1.end()) ,losser(st2.begin(),st2.end());
        ans.push_back(winner);
        ans.push_back(losser);
        return ans;

        
    }
};