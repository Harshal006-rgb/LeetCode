class Solution {
    public:
        int numRabbits(vector<int>& answers) {
            int n = answers.size();

            vector<int> hash(1001,0);
            for( int num : answers ) hash[num]++;

            int ans = 0;

            for( int i = 0 ; i < 1001 ; i++ ) {
                ans += (i+1)*((hash[i]+i)/(i+1));
            }
            
            return ans;
        }
    };