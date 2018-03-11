class Solution {
public:
    bool isMatch(string s, string p) {
        int s_Num = s.length(), p_Num = p.length();
        int i = 0, j = 0, i_Star = -1, j_Star = -1;
        for ( ; i < s_Num; ++i, ++j){
            if ('*' == p[j]){
                i_Star = i;
                while ('*' == p[j]){
                    j_Star = j;
                    ++j;
                }
            }
            if (p[j] != s[i] && '?' != p[j]){
                if (-1 != i_Star){
                    i = i_Star++;
                    j = j_Star;
                }
                else
                    return false;
            }
        }
        while ('*' == p[j]){
            ++j;
        }
        return p_Num == j;
    }
};
