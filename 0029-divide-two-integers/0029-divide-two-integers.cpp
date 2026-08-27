class Solution {
public:
    int divide(int dividend, int divisor) {
        if(divisor == dividend) return 1;
        
        bool flag = true;
        if(dividend < 0 && divisor >= 0) flag = false;
        if(divisor < 0 && dividend >= 0) flag = false;
        
        long long n = abs((long long)dividend);
        long long x = abs((long long)divisor);

        long long ans = 0;

        while( n >= x ){
            long long cnt = 0;
            while(n >= (x << (cnt + 1))){
                cnt++;
            }
            ans += 1 << cnt; 
            n -= x << cnt;
        }

        if( ans == (1 << 31) && !flag){
            return INT_MIN;
        }
        if( ans == (1 << 31)  && flag){
            return INT_MAX;
        }

        return flag ? ans : -ans;
    }
};
