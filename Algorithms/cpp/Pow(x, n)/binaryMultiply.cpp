class Solution {
public:
    double myPow(double x, int n) {
        if (0 == n)
            return 1;
        if (1 == x)
        {
            return x;
        }
        
        long long int abs_n = n;
        if (n < 0)
        {
            x = 1/x;
            abs_n = 0 - abs_n;
        }
        
        double ans = 1;
        while (abs_n)
        {
            if (abs_n & 1)
            {
                ans *= x;
            }
            x *= x;
            abs_n >>= 1;
        }
        return ans;
    }
};
