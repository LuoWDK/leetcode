class Solution {
public:
    int strStr(string haystack, string needle) {
        int len1 = haystack.length();
        int len2 = needle.length();
        if (!len2)
            return 0;
        
        int kmp[needle.length()];
        int i, j;
        
        memset(kmp, 0, sizeof(kmp));
        for (i = 0, j = 1; j < len2; ){
            if (needle[j] == needle[i]){
                kmp[j] = i + 1;
                ++i;
                ++j;
            }
            else{
                if (i > 0){
                    i = kmp[i-1];
                }
                else{
                    ++j;
                }
            }
        }
        
        for (i = 0, j = 0; i < len1; ){
            if (haystack[i] == needle[j]){
                if (j == len2 - 1)
                    return i-len2+1;
                ++i;
                ++j;
            }
            else{
                if (!j){
                    ++i;
                }
                else{
                    j = kmp[j-1];
                }
            }
        }
        return -1;
    }
};
