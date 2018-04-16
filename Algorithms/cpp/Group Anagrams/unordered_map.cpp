class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>> unmap;
        for (int i = 0; i < strs.size(); ++i)
        {
            string cnt = strs[i];
            sort(cnt.begin(), cnt.end());
            unmap[cnt].push_back(strs[i]);
        }
        
        vector<vector<string>> res(unmap.size());
        int count = 0;
        for(auto it = unmap.begin(); it != unmap.end(); ++it, ++count)
        {
            res[count].swap(it->second);
        }
        
        return res;
    }
};
