class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> ans;
        int len = nums.size();
        if (!len)
            return ans;
        vector<vector<int>> tmp;
        vector<int>::iterator it;
        vector<int> cnt(1, nums[0]);
        ans.push_back(cnt);
        
        for (int k = 1; k < nums.size(); ++k){
            tmp.clear();
            for (int i = 0; i < ans.size(); ++i){
                cnt = ans[i];
                for (int j = 0; j <= cnt.size(); ++j){
                    vector<int> next = cnt;
                    it = next.begin();
                    next.insert(it+j, nums[k]);
                    tmp.push_back(next);
                }
            }
            ans = tmp;
        }
        return ans;
    }
};
