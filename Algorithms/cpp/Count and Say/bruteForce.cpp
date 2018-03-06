class Solution {
private:
    void readOnce(string &pre){
        int len = pre.length(), i = 0, j;
        string ans = "";
        while (i < len){
            j = i;
            while (j < len && pre[j] == pre[i]){
                ++j;
            }
            ans += (to_string(j-i) + pre[i]);
            i = j;
        }
        pre.assign(ans);
    }
public:
    string countAndSay(int n) {
        string next = "1";
        for (int i = 1; i < n; ++i){
            readOnce(next);
        }
        return next;
    }
};
