class Solution {
public:
    bool isMatch(string s, string p) {
        int s_Num = s.length(), p_Num = p.length();
        int i, j, pre, tmp, dp[s.length()+1];
        memset(dp, false, sizeof(dp));
        dp[s_Num] = true;
        for (j = p_Num-1; j >= 0; --j){
            if ('*' == p[j]){
                for (i = s_Num-1; i >= 0; --i){
                    dp[i] = dp[i] || dp[i+1];
                }
            }
            else if ('?' == p[j]){
                pre = dp[s_Num];
                for (i = s_Num-1; i >= 0; --i){
                    dp[i] = dp[i] ^ pre;
                    pre = dp[i] ^ pre;
                    dp[i] =dp[i] ^ pre;
                }
            }
            else{
                pre = dp[s_Num];
                for (i = s_Num; i >= 0; --i){
                    tmp = dp[i];
                    dp[i] = (s[i] == p[j]) ? pre : false;
                    pre = tmp;
                }
            }
            dp[s_Num] = dp[s_Num] && ('*' == p[j]);
        }
        return dp[0];
    }
};
