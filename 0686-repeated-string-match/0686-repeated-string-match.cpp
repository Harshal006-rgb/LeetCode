class Solution
{
public:
    int repeatedStringMatch(string a, string b)
    {
        int n = a.size();
        int m = b.size();
        int i = 0;
        int cnt = 1;

        while( i < n ){
            if(b[0] == a[i]){
                if( i == 0 ) cnt = 0;
                int k = 0;
                int idx = i;
                while(b[k] == a[idx] && k < m){
                    k++;
                    if(idx == 0) cnt++;
                    idx = (idx+1)%n;
                }
                if(k == m) return cnt;
                else{
                    cnt = 1;
                }
            }
            i++;
        }
        return -1;
    }
};