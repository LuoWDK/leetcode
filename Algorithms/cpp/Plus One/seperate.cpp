class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        if (count(digits.begin(), digits.end(), 9) == digits.size()) {
            vector<int> res(digits.size()+1, 0);
            res[0] = 1;
            return res;
        }
        else {
            int carry = 1;
            int i = digits.size() - 1;
            while(carry) {
                carry = (carry + digits[i]) / 10;
                digits[i] = (digits[i] + 1) % 10;
                --i;
            }
            return digits;
        }
    }
};
