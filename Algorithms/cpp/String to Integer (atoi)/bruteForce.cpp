class Solution {
public:
    int myAtoi(string str) {
        string whitespace = " \t\n\v\r\f";
        int wsLen = whitespace.length();
        int strLen = str.length();
        set <char> ws;
        int i = 0, valid = -1, temp;
        long long int ans = 0;
        bool neg = false;
        
        // Record whitespace characters
        while (i < wsLen){
            ws.insert(whitespace[i]);
            ++i;
        }
        
        // Skip whitespace characters
        i = 0;
        while (ws.find(str[i]) != ws.end()){
            ++i;
        }
        
        // str is empty or it contains only whitespace characters
        if (i == strLen)
            return ans;
        
        if (str[i] == '-'){
            neg = true;
            ++valid;
            ++i;
        }
        else if (str[i] == '+'){
            ++valid;
            ++i;
        }
        else if (str[i] >= '0' && str[i] <= '9'){
            ++valid;
        }
        else
            return ans;
        
        while (i < strLen){           
            if (ans > INT_MAX){
                break;
            }
            temp = (int)(str[i] - '0');
            if (temp >= 0 && temp <=9){
                ans *= 10;
                ans += temp;
                ++i;
                ++valid;
            }
            else if (valid){
                break;
            }
            else{
                return 0;
            }            
        }
        if (ans > INT_MAX){
            return neg ? INT_MIN : INT_MAX;
        }
        return (neg) ? -1 * ans : ans;
    }
};
