class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        char* dict[128] = {NULL};
        char* i = &s[0];
        char* j = &s[0];
        // char* end = &s[s.length()-1];
        int ans = 0;
        int cnt;
        while(*j){
            cnt = *j;
            if(dict[cnt] != NULL && i < dict[cnt]+1){
                i = dict[cnt] + 1;
            }
            dict[cnt] = j;
            ++j;
            ans = max((int)(j - i), ans);
        }
        return ans;
    }
};
