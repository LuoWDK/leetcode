class Solution {
public:
    int strStr(string haystack, string needle) {
        int len1 = haystack.length();
        int len2 = needle.length();
        if (0 == len2)
            return 0;
        
        len1 -= len2;
        int i, j;
        for (i = 0; i <= len1; ++i){
            for (j = 0; j < len2; ++j){
                if (haystack[i+j] != needle[j])
                    break;
            }
            if (j == len2)
                return i;
        }
        return -1;
    }
};
