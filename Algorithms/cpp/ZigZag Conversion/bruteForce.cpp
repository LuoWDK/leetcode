class Solution {
public:
    string convert(string str, int numRows) {
        string ans = str;
        string s = str;
        int len = s.length();
        if (len <= 2 || numRows == 1)
            return s;
        
        int a = 0, cnt = 0, ind = 0, ind1 = 2 * (numRows - 1);
        int i, j;
        while (ind < len){
            ans[cnt] = s[ind];
            ++cnt;
            ++a;
            ind += ind1;
        }
        for (i = 1; i < numRows; ++i){
            ind1 = 2 * (numRows - i - 1);
            for (j = 0; j < a; ++j){
                ind = 2 * j * (numRows - 1) + i;
                if (ind < len){
                    ans[cnt] = s[ind];
                    ++cnt;
                }
                else{
                    continue;
                }
                
                ind += ind1;
                if (ind1 && (ind < len)){
                    ans[cnt] = s[ind];
                    ++cnt;
                }
            }
        }
        return ans;
    }
};
