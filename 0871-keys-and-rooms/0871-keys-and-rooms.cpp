class Solution {
public:
    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        int n = rooms.size();
        
        queue<int> q;
        q.push(0);
        vector<int> vis(n,0);
        vis[0] = 1;


        while(!q.empty()){
            int room = q.front();
            q.pop();


            for( int key : rooms[room] ) {
                if(!vis[key]){
                    q.push(key);
                    vis[key] = 1;
                }
            }
        }

        for( int i = 0 ; i < n ; i++ ) {
            if(!vis[i]) return false;
        }

        return true;
    }
};