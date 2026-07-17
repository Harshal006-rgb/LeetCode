typedef pair<int, int> pp;

class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {

        unordered_map<int,int> map;
        for( int i = 0 ; i < nums.size() ; i++ ){
            map[nums[i]]++;
        }

        priority_queue< pp ,vector<pp>, greater<pp> > pq;

        for( auto it : map ){
            int a = it.first;
            int b = it.second;
            pq.push({b,a});
            if( pq.size() > k ){
                pq.pop();
            }
        }

        vector<int> ans;

        while(!pq.empty()){
            ans.push_back(pq.top().second);
            pq.pop();
        }

        return ans;

    }
};