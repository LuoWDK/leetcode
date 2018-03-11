class Solution {
private:
    bool helper(string s, string p, int i, int j, int preI, int preJ){
        if (s.length() == i && p.length() == j){
            return true;
        }
        if (p.length() > j){
            if (s.length() == i){
                return '*' == p[j] ? helper(s, p, i, j+1, preI, preJ) : false;
            }
            else if ('?' == p[j] || s[i] == p[j])
                return helper(s, p, i+1, j+1, preI, preJ);
            else if ('*' == p[j]){
                return helper(s, p, i, j+1, i, j);
            }
        }
        if (-1 != preI){
            return helper(s, p, preI+1, preJ, preI+1, preJ);
        }
        return false;
    }
public:
    bool isMatch(string s, string p) {
        return helper(s, p, 0, 0, -1, -1);
    }
};
