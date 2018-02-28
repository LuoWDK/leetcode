class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        string str = s;
        map<char, int> myMap;
        map<char, int>::iterator it;
        int i = 0, j = 0, ans = 0;
        int len = str.length();
        while(j < len){
            it = myMap.find(str[j]);
            if (it != myMap.end()){
                if(i < it->second + 1){
                    i = it->second + 1;
                }
                it->second = j;
            }
            else{
                myMap.insert(pair<char,int>(str[j], j));
            }
            ans = max(ans, j-i+1);
            ++j;
        }
        return ans;
    }
};
