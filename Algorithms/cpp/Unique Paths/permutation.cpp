typedef long long ll;
class Solution {
public:
    int uniquePaths(int m, int n) {
        if (1 == m || 1 == n)
        {
            return 1;
        }
        
        int k = min(m-1, n-1);
        ll res = 1;
        for (int i = 1, j = m+n-2; i <= k; ++i, --j) {
            res = res * j / i;
        }
        return res;
    }
};
