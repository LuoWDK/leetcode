class Solution {
public:
    bool isPalindrome(int x) {
        if (x < 0)  return false;
        if (x < 10) return true;
        long long int reserve = 0;
        long long int temp = x * 1LL;
        int num = (int) log10(x);
        ++num;
        while(num--){
            reserve *= 10;
            reserve += (x % 10);
            x /= 10;
        }
        if (reserve == temp)
            return true;
        else
            return false;
    }
};
