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
    bool equationsPossible(vector<string>& equations) {

        DisjointSet ds(26);

        int n = equations.size();

        for( int i = 0 ; i < n ; i++ ) {
            int a = equations[i][0] - 'a';
            int b = equations[i][3] - 'a';
            char eq = equations[i][1];

            if(eq == '!') continue;
            ds.unionByRank(a,b);
        }

        for( int i = 0 ; i < n ; i++ ) {
            int a = equations[i][0] - 'a';
            int b = equations[i][3] - 'a';
            char eq = equations[i][1];

            if(eq == '=') continue;
            if( ds.findUPar(a) == ds.findUPar(b)) return false;
        }

        return true;
        
    }
};