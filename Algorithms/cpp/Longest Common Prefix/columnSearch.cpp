class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        int len = strs.size();
        if (len == 0)
            return "";
        string prefix;
        for (int i = 1; i <= strs[0].length(); ++i){
            prefix = strs[0].substr(0, i);
            for (int j = 1; j < len; ++j){
                if (strs[j].length() < i){
                    return prefix.substr(0, i-1);
                }
                if (strs[j].find(prefix) != 0){
                    return prefix.substr(0, i-1);
                }
            }
        }
        return prefix;
    }
};
