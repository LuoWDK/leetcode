class Solution {
public:
    bool isMatch(string s, string p) {
        int s_Num = s.length(), p_Num = p.length();
        int i, j = p_Num - 1, count = 0, pre, tmp;
        
        // Judge Impossiblle
        for (i = 0; i < p_Num; ++i){
            if ('*' == p[i])
                ++count;
        }
        if (p_Num-count > s_Num || (0 == count && s_Num != p_Num))
            return false;
        
        bool dp[p.length()+1];
        memset(dp, false, sizeof(dp));
        dp[p_Num] = true;
        for (i = p_Num-1; i >= 0; --i){
            if ('*' == p[i])
                dp[i] = true;
            else
                break;
        }
        for (i = s_Num-1; i >= 0; --i){
            pre = dp[p_Num];
            for (j = p_Num-1; j >= 0; --j){
                tmp = dp[j];
                if ('*' == p[j]){
                    dp[j] = tmp || dp[j+1];
                }
                else{
                    dp[j] = (pre && (s[i] == p[j] || '?' == p[j]));
                }
                pre = tmp;
            }
            dp[p_Num] = false;
        }
        return dp[0];
    }
};
