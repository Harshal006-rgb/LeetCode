class Solution {
public:
    vector<int> partitionLabels(string s) {
        int n = s.size();
        vector<int> last_pos(26, 0);
        // 1. Store the last occurrence index of each character
        for (int i = 0; i < n; i++) {
            last_pos[s[i] - 'a'] = i;
        }
        vector<int> result;
        int start_idx = 0;
        int max_last = 0;
        // 2. Greedy partition split
        for (int i = 0; i < n; i++) {
            max_last = max(max_last, last_pos[s[i] - 'a']);
            
            // If we reach the furthest index of all characters in current partition
            if (i == max_last) {
                result.push_back(i - start_idx + 1);
                start_idx = i + 1; // Move starting point to the next block
            }
        }
        return result;
    }
};