
class Solution {
public:
    bool uniqueOccurrences(vector<int>& arr) {
        unordered_map<int,int> freq , same;
        for( int num : arr  ) freq[num]++;
        
        for( auto pair : freq ) {
            if(same.find(pair.second) != same.end()) return false;
            same[pair.second]++;
        }

        return true;
    }
};