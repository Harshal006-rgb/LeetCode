typedef pair<int, int> pp;

class Solution
{
public:
    int minReorder(int n, vector<vector<int>> &connections)
    {
        vector<vector<pp>> adj(n);

        
        for (auto edge : connections)
        {
            int a = edge[0];
            int b = edge[1];
            adj[a].push_back({b,1});
            adj[b].push_back({a,0});
        }

        vector<bool> vis(n,false); 
        
        queue<int> q;
        q.push(0);
        vis[0] = true;
        int ans = 0;


        while (!q.empty())
        {
            int node = q.front();
            q.pop();

            for (auto edge : adj[node])
            {

                int num = edge.first;
                int path = edge.second;
                if( !vis[num] ){
                    if( path ) ans++;
                    q.push(num);
                    vis[num] = true;
                }
            }
        }

        return ans;
    }
};