class Solution {
public:
    string longestPalindrome(string s) {
        string s1 = s;
        int maxLen = s1.length();
        int i, j, len, ans = 1, opt = 0;
        bool dp[s1.length()][s1.length()];
        memset(dp, false, sizeof(dp));
        for (i = 0; i < maxLen; ++i){
            dp[i][i] = true;
        }
        for (i = 0; i < maxLen - 1; ++i){
            if (s1[i] == s1[i+1]){
                dp[i][i+1] = true;
                ans = 2;
                opt = i;
            }
        }
        for (len = 3; len <= maxLen; ++len){
            i = 0;
            j = i + len - 1;
            while (j < maxLen){
                if (s1[i] == s1[j] && dp[i+1][j-1]){
                    dp[i][j] = true;
                    if (len > ans){
                        ans = len;
                        opt = i;
                    }
                }
                ++i;
                j = i + len - 1;
            }
        }
        string s2 = s1.substr(opt, ans);
        return s2;
    }
};
