class Solution {
private:
    string addString(string s1, string s2){
        int i = s1.length()-1, j = s2.length()-1;
        if (i > j)
            return addString(s2, s1);
        int carry = 0;
        string req = "";
        while (i >= 0){
            carry += (s1[i] - '0') + (s2[j] - '0');
            req = (char)('0' + (carry%10)) + req;
            carry /= 10;
            --i;
            --j;
        }
        while (j >= 0){
            carry += s2[j] - '0';
            req = (char)('0' + (carry%10)) + req;
            carry /= 10;
            --j;
        }
        if (carry){
            req = (char)('0' + (carry%10)) + req;
        }
        return req;
    }
public:
    string multiply(string num1, string num2) {
        if (num1 == "0" || num2 == "0")
            return "0";
        long long int carry = 0, n1, n2, start = -1;
        string tmp = "", ans = "0";
        bool flag;
        while (num1.length()){
            ++start;
            n1 = num1.back() - '0';
            num1.pop_back();
            if (!n1){
                continue;
            }
            carry = 0;
            tmp.assign(start, '0');
            for (int i = num2.length() - 1; i >= 0; --i){
                n2 = num2[i] - '0';
                carry += n1 * n2;
                tmp = (char)('0' + (carry%10)) + tmp;
                carry /= 10;
            }
            while (carry){
                tmp = (char)('0' + (carry%10)) + tmp;
                carry /= 10;
            }
            ans = addString(tmp, ans);
        }
        return ans;
    }
};
