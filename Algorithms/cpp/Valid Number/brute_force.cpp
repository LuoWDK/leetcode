class Solution {
public:
    bool isNumber(string s) {
        int i = 0;
        
//         Delete ' '
        for (; ' ' == s[i]; ++i) {}

//         Delete '-' and '+'
        if ('-' == s[i]|| '+' == s[i]) {
            ++i;
        }
        
//         Delete XX.XX
        int n_number = 0, n_point = 0;
        for (; (s[i] >= '0' && s[i] <= '9') || '.' == s[i]; ++i) {
            '.' == s[i] ? (++n_point) : (++n_number);
        }
        if (n_point > 1 || n_number < 1) {
            return false;
        }
        
//         Delete e+XX and e-XX
        if ('e' == s[i]) {
            ++i;
            if ('-' == s[i]|| '+' == s[i]) {
                ++i;
            }
            
            n_number = 0;
            for(; s[i] >= '0' && s[i] <= '9'; ++i) {
                ++n_number;
            }
            if (n_number < 1)
                return false;
        }
        
        for(; ' ' == s[i]; ++i) {}
        
        return 0 == s[i];
    }
};
