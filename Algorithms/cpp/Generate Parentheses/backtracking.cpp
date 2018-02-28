class Solution {
public:
    vector<string> generateParenthesis(int n) {
        vector<string> ans;
        if (0 == n)
            return ans;
        int haveRight = n;
        string cnt = "";
        backtracking(ans, cnt, n, haveRight);
        return ans;
    }
    
    void backtracking(vector<string> &ans, string &cnt, int &n, int &haveRight){
        if (!n && !haveRight){
            ans.push_back(cnt);
            return;
        }
        if (!n && haveRight){
            cnt.push_back(')');
            --haveRight;
            backtracking(ans, cnt, n, haveRight);
            ++haveRight;
            cnt.pop_back();
        }
        if (n){
            cnt.push_back('(');
            --n;
            backtracking(ans, cnt, n, haveRight);
            ++n;
            cnt.pop_back();
            if (haveRight > n){
                cnt.push_back(')');
                --haveRight;
                backtracking(ans, cnt, n, haveRight);
                ++haveRight;
                cnt.pop_back();                
            }
        }
    }
};
