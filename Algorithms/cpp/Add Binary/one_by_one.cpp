class Solution {
public:
    string addBinary(string a, string b) {
        if (a.length() > b.length()) {
            return addBinary(b, a);
        }        
        if (a.empty()) {
            return b;
        }
        
        string res;
        int aInd = a.length()-1, bInd = b.length()-1;
        int carry = 0;
        while (aInd >= 0 && bInd >= 0) {
            carry += (a[aInd] - '0') + (b[bInd] - '0');
            res = (char)((carry%2) + '0') + res;
            carry /= 2;
            --aInd;
            --bInd;
        }
        while (bInd >= 0) {
            carry += (b[bInd] - '0');
            res = (char)((carry%2) + '0') + res;
            carry /= 2;
            --bInd;            
        }
        while (carry) {
            res = (char)((carry%2) + '0') + res;
            carry /= 2;            
        }
        return res;
    }
};
