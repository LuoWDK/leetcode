class Solution {
public:
    int divide(int dividend, int divisor) {
        if (0 == divisor || (INT_MIN == dividend && -1 == divisor))
            return INT_MAX;
        if (0 == dividend)
            return 0;
        
        bool flag = (dividend < 0) ^ (divisor < 0) ? 0 : 1;
        long long int ans = 0, a = dividend, b = divisor;
        a = labs(a);
        b = labs(b);
        if (1 == b)
            return flag ? a : -a;
        while (a >= b){
            long long int step = 1;
            long long int temp = b;
            while (a >= (temp << 1)){
                temp <<= 1;
                step <<= 1;
            }
            a -= temp;
            ans += step;
        }
        
        return flag ? ans : -ans;
    }
};
