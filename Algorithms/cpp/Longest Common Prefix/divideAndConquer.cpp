class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        int len = strs.size();
        if(0 == len)
            return "";
        return longestCommonPrefix(strs, 0, len-1);
    }

private:
    string longestCommonPrefix(vector<string>& strs, int left, int right){
        if (left == right){
            return strs[left];
        }
        int mid = (left + right) >> 1;
        string pre1 = longestCommonPrefix(strs, left, mid);
        if (0 == pre1.length())
            return "";
        string pre2 = longestCommonPrefix(strs, mid+1, right);
        if (0 == pre2.length())
            return "";
        return findCommonPrefix(pre1, pre2);
    }
    string findCommonPrefix(string s1, string s2){
        int minLen = min(s1.length(), s2.length());
        for (int i = 0; i < minLen; ++i){
            if (s1[i] != s2[i]){
                return s1.substr(0, i);
            }
        }
        return s1.substr(0, minLen);
    }
};
