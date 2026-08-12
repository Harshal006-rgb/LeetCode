class Solution {
public:
    int minimumPushes(string word) {
        int n = word.size();
        int ans = 0;
        int pushmultiplier = 1;

        while(n>0){
            ans += min(n,8)*pushmultiplier;
            pushmultiplier++;
            n-=8;
        }
        return ans;
    }
};