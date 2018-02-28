class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        string str = s;
        int dict[128];
        memset(dict, -1, sizeof(dict));
        int i = 0, j = 0, ans = 0;
        int len = str.length();
        int cnt;
        while(j < len){
            cnt = (int)str[j];
            if (dict[cnt] != -1){
                if (i < dict[cnt] + 1){
                    i = dict[cnt] + 1;
                }
            }
            dict[cnt] = j;
            ++j;
            ans = max (ans, j - i);
        }
        return ans;
    }
};
