class DisjointSet
{
public:
    vector<int> rank, parent, size;
    DisjointSet(int n)
    {
        rank.resize(n + 1, 0);
        size.resize(n + 1, 1); // Every node initially has size 1
        parent.resize(n + 1);
        for (int i = 0; i <= n; i++)
        {
            parent[i] = i;
        }
    }

    // Find ultimate parent (with Path Compression)
    int findUPar(int node)
    {
        if (node == parent[node])
            return node;
        return parent[node] = findUPar(parent[node]);
    }

    // 1. Union by Rank
    void unionByRank(int u, int v)
    {
        int ulp_u = findUPar(u);
        int ulp_v = findUPar(v);
        if (ulp_u == ulp_v)
            return;
        if (rank[ulp_u] < rank[ulp_v])
        {
            parent[ulp_u] = ulp_v;
        }
        else if (rank[ulp_v] < rank[ulp_u])
        {
            parent[ulp_v] = ulp_u;
        }
        else
        {
            parent[ulp_v] = ulp_u;
            rank[ulp_u]++;
        }
    }

    // 2. Union by Size
    void unionBySize(int u, int v)
    {
        int ulp_u = findUPar(u);
        int ulp_v = findUPar(v);
        if (ulp_u == ulp_v)
            return;

        if (size[ulp_u] < size[ulp_v])
        {
            parent[ulp_u] = ulp_v;
            size[ulp_v] += size[ulp_u];
        }
        else
        {
            parent[ulp_v] = ulp_u;
            size[ulp_u] += size[ulp_v];
        }
    }
};


class Solution {
public:
    int largestIsland(vector<vector<int>>& grid) {
        int n = grid.size();
        DisjointSet ds(n*n);

        vector<int> erow = {0,0,1,-1};
        vector<int> ecol = {-1,1,0,0};
        
        int ans = 0;

        for( int i = 0 ; i < n ; i++ ) {
            for( int j = 0 ; j < n ; j++ ) {

                if( grid[i][j] == 1) {
                    int size = 0;
                    int element1 = i*n + j;
                    for( int k = 0 ; k < 4 ; k++ ) {
                        int nrow = erow[k] + i;
                        int ncol = ecol[k] + j;
                        if( nrow >= 0 && ncol >= 0 && nrow < n && ncol < n && grid[nrow][ncol] ){
                            int element2 = nrow*n + ncol;
                            ds.unionBySize(element1,element2);
                        }
                    }
                    int parent = ds.findUPar(element1);
                    size += ds.size[parent];
                    ans = max(ans,size);

                } 

            }
        }


        for( int i = 0 ; i < n ; i++ ) {
            for( int j = 0 ; j < n ; j++ ) {
                
                if( grid[i][j] == 0) {
                    unordered_set<int> st;
                    int size = 0;
                    for( int k = 0 ; k < 4 ; k++ ) {
                        int nrow = erow[k] + i;
                        int ncol = ecol[k] + j;
                        if( nrow >= 0 && ncol >= 0 && nrow < n && ncol < n && grid[nrow][ncol] ){
                            int element2 = nrow*n + ncol;
                            int parent = ds.findUPar(element2);
                            if(st.find(parent) != st.end()) continue;
                            st.insert(parent);
                            size += ds.size[parent];
                        }
                    }
                    size++;
                    ans = max(ans,size);
                } 
            }
        }
        return ans;
    }
};