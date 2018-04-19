class Solution {
public:
    int mySqrt(int x) {
        long left = 1, right = x, mid;
        while (left <= right) {
            mid = (left + right) >> 1;
            if (mid * mid > x) {
                right = mid - 1;
            }
            else {
                if ((mid+1) * (mid+1) > x) {
                    return mid;
                }
                left = mid + 1;
            }
        }
        return x;
    }
};
