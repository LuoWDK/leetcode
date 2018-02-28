class Solution {
public:
    
    vector<string> letterCombinations(string digits) {
        vector<string> ans;
        if (0 == digits.length()){
            return ans;
        }
        string trans[10] = {"", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
        ans.push_back("");
        for (int i = 0; i < digits.length(); ++i){
            int num = digits[i] - '0';
            vector<string> temp;
            for (int j = 0; j < trans[num].length(); ++j){
                for (int k = 0; k < ans.size(); ++k){
                    temp.push_back(ans[k] + trans[num].at(j));
                }
            }
            ans = temp;
        }
        
        return ans;
    }
};
