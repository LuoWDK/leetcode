class Solution {
public:
    int lengthOfLongestSubstring(string str) {
        string s = str;
        set<char> win;
        set<char>::iterator it;
        int i = 0, j = 0, ans = 0, len = s.length();
        while (j < len){
            it = win.find(s[j]);
            if (it == win.end()){
                win.insert(s[j]);
                ++j;
                if (ans < j - i){
                    ans = j - i;
                }
            }
            else{
                win.erase(s[i]);
                ++i;
            }
        }
        return ans;
    }
};
