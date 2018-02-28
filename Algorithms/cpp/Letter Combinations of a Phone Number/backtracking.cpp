class Solution {
public:
    
    vector<string> letterCombinations(string digits) {
        vector<string> ans;
        if (0 == digits.length()){
            return ans;
        }
        string cnt = "";
        string trans[10] = {"", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
        backtracking(digits, 0, ans, cnt, trans);
        return ans;
    }
    
    void backtracking(string &digits, int index, vector<string> &ans, string &cnt, string trans[]){
        if (index == digits.length()){
            ans.push_back(cnt);
        }
        int num = digits[index] - '0';
        if (num < 0 || num > 9)
            return;
        else if (0 == num || 1 == num){
            backtracking(digits, index+1, ans, cnt, trans);
        }
        else{
            for (int i = 0; i < trans[num].length(); ++i){
                cnt.push_back(trans[num].at(i));
                backtracking(digits, index+1, ans, cnt, trans);
                cnt.pop_back();
            }            
        }
    }
};
