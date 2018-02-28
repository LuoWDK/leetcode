class Solution {
public:
    bool isMatch(string s, string p) {
        int s_Num = s.length();
        int p_Num = p.length();
        if (!s_Num && !p_Num)
            return true;
               
        if (s_Num == 0){
            if (p_Num > 1 && p[1] == '*'){
                return isMatch(s, p.substr(2));
            }
            return false;
        }
        if (p_Num == 0)
            return false;
        
        if (p[0] == s[0] || p[0] == '.'){
            if (p_Num > 1 && p[1] == '*')
            {
                bool flag = isMatch(s.substr(1), p);
                if (flag)
                    return true;
                flag = isMatch(s, p.substr(2));
                if (flag)
                    return true;
            }
            return isMatch(s.substr(1), p.substr(1));
        }
        else{
            if (p_Num > 1 && p[1] == '*')
            {
                return isMatch(s, p.substr(2));
            }
            return false;
        }
        
        return false;
    }
};
