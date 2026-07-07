class Solution {
public:
    int networkDelayTime(vector<vector<int>> &times, int n, int k)
    {
        vector<vector<pair<int, int>>> adj(n+1);
        for (auto edge : times)
        {
            int a = edge[0];
            int b = edge[1];
            int t = edge[2];
            adj[a].push_back({b, t});
        }

        vector<int> time(n+1,INT_MAX);
        
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        pq.push({0, k});
        time[k] = 0;

        while (!pq.empty())
        {
            auto it = pq.top();
            int node = it.second;
            int t = it.first;
            pq.pop();

            for (auto edge : adj[node])
            {
                int num = edge.first;
                int l = edge.second;

                if (time[num] > t + l)
                {
                    time[num] = t + l;
                    pq.push({time[num], num});
                }
            }
        }

        int maxi = 0;
        for( int i = 1 ; i < n+1 ; i++ ) {
            if( time[i] == INT_MAX) return -1;
            maxi = max( maxi , time[i]);
        }

        return maxi;

    }


};