class Solution {
public:
    int romanCharToInt(char c) {
        switch (c) {
            case 'I': 	return 1;
            case 'V':	return 5;
            case 'X':	return 10;
            case 'L':	return 50;
            case 'C':	return 100;
            case 'D':	return 500;
            case 'M':	return 1000;
            default:	return 0;
        }
    }
    int romanToInt(string s) {
        int ans = romanCharToInt(s.back());
        int temp1, temp2;
        for (int i = s.size() - 2; i >= 0; --i){
            temp1 = romanCharToInt(s[i]);
            temp2 = romanCharToInt(s[i+1]);
            ans += (temp1 < temp2 ? -temp1 : temp1);
        }
        return ans;
    }
};
