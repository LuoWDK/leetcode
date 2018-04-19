class Solution {
public:
    string addBinary(string a, string b) {
        string res;
        int i = a.length()-1, j = b.length()-1, c = 0;
        while (i >= 0 || j >= 0 || c) {
            c += (i >= 0 ? (a[i--] - '0') : 0);
            c += (j >= 0 ? (b[j--] - '0') : 0);
            res = char('0' + c % 2) + res;
            c /= 2;
        }
        
        return res;
    }
};
