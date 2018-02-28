class Solution {
public:
    bool isMatch(string s, string p) {
        int s_Num = s.length();
        int p_Num = p.length();
        
        if (!s_Num && !p_Num)
            return true;
        if (!p_Num)
            return false;
        
        int i, j;
        bool flag;
        bool dp[s.length()+1][p.length()+1];
        memset(dp, false, sizeof(dp));
        dp[0][0] = true;
        
        for (j = 0; j < p_Num; ++j){
            if('*' == p[j] && dp[0][j-1]){
                dp[0][j+1] = true;
            }
        }
        
        for (i = 0; i < s_Num; ++i){
            for (j = 0; j < p_Num; ++j){
                if ('*' == p[j]){
                    if (dp[i+1][j] || dp[i+1][j-1])
                        dp[i+1][j+1] = true;
                }
                else if(s[i] == p[j] || '.' == p[j]){
                    if (dp[i][j]){
                        dp[i+1][j+1] = true;
                    }
                    else if (j+1 < p_Num && '*' == p[j+1] && dp[i][j+1]){
                        dp[i+1][j+1] = true;
                    }
                    else if (j > 1 && '*' == p[j-1] && dp[i][j-2]){
                        dp[i+1][j+1] = true;
                    }
                }
            }
        }
        return dp[s_Num][p_Num];
    }
};
