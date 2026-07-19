class Solution
{
public:
    int repeatedStringMatch(string a, string b)
    {
        int n = a.size();
        int m = b.size();
        int cnt = m/n;

        string na = "";

        int i = 0;
        while(i < cnt){
            na += a;
            i++;
        }

        if( na.find(b) != std::string::npos) return cnt;
        na += a;
        if( na.find(b) != std::string::npos) return cnt+1;
        na += a;
        if( na.find(b) != std::string::npos) return cnt+2;
        return -1;
    }
};