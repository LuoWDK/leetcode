class Solution {
public:
    int longestValidParentheses(string s) {
        int len = s.length();
        stack<int> left;
        int ans = 0;
        left.push(-1);
        for (int i = 0; i < len; ++i){
            switch (s[i]){
                case '(':
                    left.push(i);
                    break;
                case ')':
                    left.pop();
                    if (left.empty())
                        left.push(i);
                    else{
                        ans = max (ans, i - left.top());
                    }
                    break;
                default:
                    break;
            }
        }
        return ans;
    }
};
