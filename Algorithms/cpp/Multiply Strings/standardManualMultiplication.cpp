class Solution {
public:
    string multiply(string num1, string num2) {
        string ans(num1.length() + num2.length(), '0');
        
        int carry = 0;
        for (int i = num1.length() - 1; i >= 0; --i){
            carry = 0;
            for (int j = num2.length() - 1; j >= 0; --j){
                carry += (ans[i+j+1]-'0') + (num1[i]-'0') * (num2[j]-'0');
                ans[i+j+1] = '0' + (carry % 10);
                carry /= 10;
            }
            ans[i] += carry;
        }
        size_t startPos = ans.find_first_not_of("0");
        if (string::npos != startPos){
            return ans.substr(startPos);
        }
        return "0";
    }
};
