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
    vector<vector<string>> accountsMerge(vector<vector<string>>& accounts) {
        int n = accounts.size();
        unordered_map<string,int> mapMail;

        DisjointSet ds(n);

        for( int i = 0 ; i < n ; i++ ) {
            for( int j = 1 ; j < accounts[i].size() ; j++) {
                string mail = accounts[i][j];

                if(mapMail.find(mail) == mapMail.end()){
                    mapMail[mail] = i;
                }
                else{
                    ds.unionByRank(i,mapMail[mail]);       
                }
            }
        }

        vector<vector<string>> mergeMail(n);
        for( auto it : mapMail ) {
            string mail = it.first;
            int node = ds.findUPar(it.second);
            mergeMail[node].push_back(mail);
        }

        vector<vector<string>> ans;

        for( int i = 0 ; i < n ; i++ ) {
            if(mergeMail[i].size() == 0 ) continue;
            sort(mergeMail[i].begin(),mergeMail[i].end());
            string name = accounts[i][0];
            vector<string> temp;
            temp.push_back(name);
            for( auto it : mergeMail[i]){
                temp.push_back(it);
            }
            ans.push_back(temp);
        }

        return ans;
        
    }
};
