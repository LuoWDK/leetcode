class Solution {
public:
    int longestValidParentheses(string s) {
        int len = s.length();
        int ans = 0;
        int dp[s.length()+1];
        memset(dp, 0, sizeof(dp));
        for (int i = 1; i < len; ++i){
            if (')' == s[i]){
                if ('(' == s[i-1]){
                    dp[i] = 2 + (i>=2 ? dp[i-2] : 0);
                }
                else if (i - dp[i-1] > 0 && '(' == s[i-dp[i-1]-1]){
                    dp[i] = 2 + dp[i-1] + (i-dp[i-1]>=2 ? dp[i-dp[i-1]-2] : 0);
                }
                ans = max(ans, dp[i]);
            }
        }
        return ans;
    }
};
