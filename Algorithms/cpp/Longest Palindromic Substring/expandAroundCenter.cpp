class Solution {
public:
    inline int checkLongestPalindrome(string s, int left, int right, int maxLen){
        int k = 0;
        while (left - k >= 0 && right + k < maxLen){
            if (s[left-k] != s[right+k]){
                break;
            }
            ++k;
        }
        return right - left + k + k - 1;
    }
    
    string longestPalindrome(string s) {
        int i, cnt, cnt1, cnt2;
        int ans = 1, opt = 0;
        int maxLen = s.length();
        for (i = 0; i < maxLen - 1; ++i){
            cnt1 = checkLongestPalindrome(s, i, i, maxLen);
            cnt2 = checkLongestPalindrome(s, i, i + 1, maxLen);
            cnt = max(cnt1, cnt2);
            if (cnt > ans){
                ans = cnt;
                if (cnt & 1){
                    opt = i - (cnt >> 1);
                }
                else{
                    opt = i - (cnt >> 1) + 1;
                }
            }
        }
        return s.substr(opt, ans);
    }
};
