
class Solution {
public:
    bool isNStraightHand(vector<int>& hand, int groupSize) {
        int n = hand.size();
        if(n%groupSize) return false;
        map<int,int> mp;
        for( int i = 0 ; i < n ; i++ ) {
            mp[hand[i]]++;
        }

        while(!mp.empty()){

            int curr = mp.begin()->first;
            
            for( int i = 0 ; i < groupSize ; i++ ) {
                if(mp.find(curr) == mp.end()) return false;
                mp[curr]--;
                if(mp[curr] == 0 ) mp.erase(curr);
                curr++;
            }

        }

        return true;
    }
};