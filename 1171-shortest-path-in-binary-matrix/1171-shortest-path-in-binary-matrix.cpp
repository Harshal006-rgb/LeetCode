class Solution
{
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();

        if (grid[0][0] != 0 || grid[n-1][m-1] != 0) return -1;
        
        vector<vector<int>> dis(n,vector<int>(m,INT_MAX));
        priority_queue<pair<int,pair<int,int>>, vector<pair<int,pair<int,int>>>, greater<pair<int,pair<int,int>>>> pq;
        int cost = 0;
        pq.push({1,{0,0}});
        dis[0][0] = 1;

        vector<int> erow = {-1, -1, -1, 0, 0, 1, 1, 1};
        vector<int> ecol = {-1, 0, 1, -1, 1, -1, 0, 1};


        while(!pq.empty()){
            auto it = pq.top();
            int row = it.second.first;
            int col = it.second.second;
            
            pq.pop();

            if( row == n-1 && col == m-1 ) return dis[n-1][m-1];

            for( int i = 0 ; i < 8 ; i++ ) {

                int nrow = row + erow[i];
                int ncol = col + ecol[i];
                if( nrow >= 0 && nrow < n && ncol >= 0 && ncol < m && grid[nrow][ncol] == 0 ){
                    if(dis[nrow][ncol] > dis[row][col] + 1){
                        dis[nrow][ncol] = dis[row][col] + 1;
                        pq.push({dis[nrow][ncol],{nrow,ncol}});
                    }
                }
            }
        }

        return -1;
       

    }
};
