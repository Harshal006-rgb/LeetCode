
class Solution {
public:
    vector<int> successfulPairs(vector<int>& spells, vector<int>& potions, long long success) {
        int n = spells.size();
        int m = potions.size();
        vector<int> pairs;
        sort(potions.begin(),potions.end());
        

        for( int spell : spells ) {
            int low = 0 , high = m-1;

            while(low <= high){
                int mid = low - (low-high)/2;
                if( (long long)potions[mid]*spell >= (long long)success){
                    high = mid - 1;
                }
                else low = mid + 1;
            }
            pairs.push_back(m-low);            
        }

        return pairs;
    }
};