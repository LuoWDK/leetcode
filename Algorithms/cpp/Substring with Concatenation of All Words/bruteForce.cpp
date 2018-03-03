class Solution {
public:
    vector<int> findSubstring(string s, vector<string>& words) {
        vector <int> ans;
        int len1 = s.length();
        int len2 = words.size();
        if (!len1 || !len2)
            return ans;
        
        unordered_map<string, int> dict;
        unordered_map<string, int> tdict;
        int wl = words[0].length();
        int i, j;
        string str, str1;
        for (i = 0; i < len2; ++i){
            dict[words[i]]++;
        }
        
        for (i = 0; i < len1 - wl * len2 + 1; ++i){
            tdict.clear();
            j = 0;
            while(j < len2){
                str = s.substr(i+j*wl, wl);
                if (dict.count(str)){
                    tdict[str]++;
                    if (tdict[str] > dict[str])
                        break;
                }
                else{
                    break;
                }
                ++j;
            }
            if (len2 == j){
                ans.push_back(i);
            }
        }
        
        return ans;
    }
};
