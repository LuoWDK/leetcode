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
        int i, j, left, count;
        string str, str1;
        for (i = 0; i < len2; ++i){
            dict[words[i]]++;
        }
        for (i = 0; i < wl; ++i){
            tdict.clear();
            left = i;
            count = 0;
            for (j = i; j <= len1 - wl; j += wl){
                str = s.substr(j, wl);
                if (dict.count(str)){
                    tdict[str]++;
                    if (tdict[str] <= dict[str]){
                        ++count;
                    }
                    else{
                        while (tdict[str] > dict[str]){
                            str1 = s.substr(left, wl);
                            tdict[str1]--;
                            if (tdict[str1] < dict[str])
                                --count;
                            left += wl;
                        }
                    }
                    if (count == len2){
                        ans.push_back(left);
                        str1 = s.substr(left, wl);
                        tdict[str1]--;
                        --count;
                        left += wl;
                    }
                }
                else{
                    tdict.clear();
                    left = j + wl;
                    count = 0;
                }
            }
        }
        return ans;
    }
};
