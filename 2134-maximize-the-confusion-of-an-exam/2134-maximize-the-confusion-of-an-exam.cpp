class Solution {
public:
    int maxConsecutiveAnswers(string answerKey, int k) {
        int n = answerKey.size();
        unordered_map<char,int> mp;
        int l = 0 , r = 0;
        int size = 0;

        while(r<n){
            mp[answerKey[r]]++;

            int mini = min(mp['T'],mp['F']);
            while(mini > k ){
                mp[answerKey[l]]--;
                l++;
                mini = min(mp['T'],mp['F']);
            }
            size = max(size,r-l+1);
            r++;
            
        }
        return size;
    }
};