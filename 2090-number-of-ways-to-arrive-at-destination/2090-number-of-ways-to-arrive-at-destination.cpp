class Solution {
public:
    int countPaths(int n, vector<vector<int>>& roads) {
        vector<vector<pair<int,int>>> adj(n);
        for( auto edge : roads ) {
            int a = edge[0];
            int b = edge[1];
            int t = edge[2];
            adj[a].push_back({b,t});
            adj[b].push_back({a,t});           
        }

        int mod = (int)(1e9 + 7);

        priority_queue<pair<long long, long long>,vector<pair<long long, long long>>, greater<pair<long long, long long>>> pq;
        pq.push({0,0});
        vector<long long> time(n,LLONG_MAX) , ways(n,0);
        ways[0] = 1;
        time[0] = 0;

        while(!pq.empty()){
            auto it = pq.top();
            int node = it.second;
            long long t = it.first;
            pq.pop();

            for( auto edge : adj[node]){
                int num = edge.first;
                long long l = edge.second;

                if(time[num] > t + l){
                    time[num] = t + l;
                    ways[num] = ways[node];
                    pq.push({time[num],num});
                }
                else if ( time[num] == t + l){
                    ways[num] = (ways[num] + ways[node])% mod;
                }
            }
        }

        return ways[n-1]% mod;
    }
};