class Solution {
public:
    int mySqrt(int x) {
        double ans = x;
        double inf = 0.0001;
        while (fabs(pow(ans, 2) - x) > inf) {
            ans = (ans + x / ans) / 2;
        }
        return ans;
    }
};
