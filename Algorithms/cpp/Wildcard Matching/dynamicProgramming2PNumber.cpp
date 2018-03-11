class Solution {
public:
    bool isMatch(string s, string p) {
        int i, j, cur, pre, s_Num = s.length(), p_Num = p.length();
        bool dp[2][p.length()+1];
        memset(dp, false, sizeof(dp));
        
        cur = 1 & s_Num;
        dp[cur][p_Num] = true;
        for (j = p_Num-1; j >= 0; --j){
            if ('*' == p[j])
                dp[cur][j] = true;
            else
                break;
        }
        
        for (i = s_Num-1; i >= 0; --i){
            cur = 1 & i;
            pre = 1 - cur;
            for (j = p_Num-1; j >=0; --j){
                if (s[i] == p[j] || '?' == p[j])
                    dp[cur][j] = dp[pre][j+1];
                else if ('*' == p[j])
                    dp[cur][j] = dp[pre][j] || dp[cur][j+1];
                else
                    dp[cur][j] = false;
            }
            dp[cur][p_Num] = false;
        }
        return dp[0][0];
    }
};
