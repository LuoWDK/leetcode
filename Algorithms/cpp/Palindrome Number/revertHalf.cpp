class Solution {
public:
    bool isPalindrome(int x) {
        if (x < 0)  return false;
        if (x < 10) return true;
        
        int reserve = 0;
        int num = (int)log10(x) + 1;
        int i = num / 2;
        while (i){
            reserve *= 10;
            reserve += (x % 10);
            x /= 10;
            --i;
        }
        if (num & 1)
            x /= 10;
        if (reserve == x)
            return true;
        else
            return false;
    }
};
