class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        int len = strs.size();
        if (len == 0){
            return "";
        }
        
        int minLen = strs[0].length();
        for (int i = 1; i < len; ++i){
            if (minLen > strs[i].length()){
                minLen = strs[i].length();
            }
        }
        if (minLen == 0){
            return "";
        }
        
        int left = 1, right = minLen, mid = 0, ans = 0;
        bool flag;
        while(left <= right){
            mid = (left + right) >> 1;
            flag = isCommonPrefix(strs, mid);
            if (flag){
                left = mid + 1;
                ans = max(mid, ans);
            }
            else{
                right = mid - 1;
            }
        }
        return strs[0].substr(0, ans);
    }
    
    bool isCommonPrefix(vector<string>& strs, int num){
        string prefix;
        int len = strs.size();
        prefix = strs[0].substr(0, num);
        for(int j = 1; j < len; ++j){
            if (strs[j].find(prefix) != 0){
                return false;
            }
        }
        return true;
    }
};
