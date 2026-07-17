class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {

        unordered_map<int,int> map;
        for( int i = 0 ; i < nums.size() ; i++ ){
            map[nums[i]]++;
        }

        vector<pair<int,int>> bucket;
        for( auto x: map){
            bucket.push_back({x.second,x.first});
        }

        sort(bucket.begin(),bucket.end());
        
        vector<int> ans;

        for( int i = bucket.size()-1 ; i >= 0 ;i--){
            ans.push_back(bucket[i].second);
            if(ans.size() >= k) break;
        }

        return ans ;
    }
};