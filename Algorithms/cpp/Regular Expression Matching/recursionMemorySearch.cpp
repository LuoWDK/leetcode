class Solution {
public:
    bool isAnswer(int i, int j, string s, string p, vector<vector<int>> &dp){
        if (dp[i][j] != -1)
            return dp[i][j];
        bool ans = false;
        int s_Num = s.length(), p_Num = p.length();
        if (j == p_Num){
            ans = (i == s_Num);
        }
        else if (i == s_Num) {
            if (j+1 < p_Num && '*' == p[j+1]){
                ans = isAnswer(i, j+2, s, p, dp);
            }
        }
        else{
            if (s[i] == p[j] || '.' == p[j]){
                if (j+1 < p_Num && '*' == p[j+1]){
                    ans = isAnswer(i+1, j, s, p, dp);
                    if (!ans){
                        ans = isAnswer(i, j+2, s, p, dp);
                    }
                }
                else{
                    ans = isAnswer(i+1, j+1, s, p, dp);
                }
            }
            else if (j+1 < p_Num && '*' == p[j+1]){
                ans = isAnswer(i, j+2, s, p, dp);
            }
        }
        dp[i][j] = ans;
        return ans;
    }
    
    bool isMatch(string s, string p) {
        if (p.empty()) return s.empty();
        vector<vector<int>> dp(s.length() + 1, vector<int>(p.length() + 1, -1));
        return isAnswer(0, 0, s, p, dp);        
    }
};
