class Solution {
public:
    bool isValid(string s) {
        stack<char> check;
        for (int i = 0; i < s.length(); ++i){
            char c = s[i];
            switch(c){
                case '(':
                    check.push('(');
                    break;
                case '{':
                    check.push('{');
                    break;
                case '[':
                    check.push('[');
                    break;
                case ')':
                    if (check.empty() || check.top() != '('){
                        return false;
                    }
                    check.pop();
                    break;
                case ']':
                    if (check.empty() || check.top() != '['){
                        return false;
                    }
                    check.pop();
                    break;
                case '}':
                    if (check.empty() || check.top() != '{'){
                        return false;
                    }
                    check.pop();
                    break;
                default:
                    return false;
            }
        }
        if (check.empty())
            return true;
        return false;
    }
};
