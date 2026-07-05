class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        int n = numCourses;
        vector<vector<int>> adj(n);
        for( auto edge : prerequisites) {
            int u = edge[0];
            int v = edge[1];
            adj[u].push_back(v);         
        }

        vector<int> topo;
        vector<int> indegree(n,0);

        for( auto edge : adj ) {
            for( int node :  edge ) {
                indegree[node]++;
            }
        }

        queue<int> q;

        for( int i = 0 ; i < n ; i++ ) {
            if(indegree[i] == 0 ) q.push(i);
        }


        while(!q.empty()){
            int node = q.front();
            q.pop();
            topo.push_back(node);

            for( int edge : adj[node]){
                indegree[edge]--;
                if(indegree[edge] == 0 ) q.push(edge);
            }
        }

        if(topo.size() != n ) return false;
        return true;




    }
};