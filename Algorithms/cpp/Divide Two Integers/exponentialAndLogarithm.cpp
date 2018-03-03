class Solution {
public:
    int divide(int dividend, int divisor) {
        if (0 == divisor || (INT_MIN == dividend && -1 == divisor))
            return INT_MAX;
        if (0 == dividend)
            return 0;
        
        bool flag = (dividend < 0) ^ (divisor < 0) ? 0 : 1;
        double a = log(fabs(dividend));
        double b = log(fabs(divisor));
        long long int ans = exp(a - b);
        
        return flag ? ans : -ans;
    }
};
