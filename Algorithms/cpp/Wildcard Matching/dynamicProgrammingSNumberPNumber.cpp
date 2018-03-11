class Solution {
public:
    bool isMatch(string s, string p) {
        int i, j, s_Num = s.length(), p_Num = p.length();
        bool dp[s.length()+1][p.length()+1];
        memset(dp, false, sizeof(dp));
        dp[s_Num][p_Num] = true;
        
        for (j = p_Num-1; j >= 0; --j){
            if ('*' == p[j])
                dp[s_Num][j] = true;
            else
                break;
        }
        
        for (i = s_Num-1; i >= 0; --i){
            for (j = p_Num-1; j >=0; --j){
                if (s[i] == p[j] || '?' == p[j])
                    dp[i][j] = dp[i+1][j+1];
                else if ('*' == p[j])
                    dp[i][j] = dp[i+1][j] || dp[i][j+1];
                else
                    dp[i][j] = false;
            }
        }
        return dp[0][0];
    }
};
