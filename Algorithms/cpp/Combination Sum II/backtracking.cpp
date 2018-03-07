class Solution {
private:
    void backtrack(vector<vector<int>>& ans, vector<int>& cnt, int target, vector<int>& candidates, int index){
        if (!target){
            ans.push_back(cnt);
            return;
        }
        if (index == candidates.size())
            return;
        int i = index;
        for (int i = index; i < candidates.size() && candidates[i] <= target; ++i){
            cnt.push_back(candidates[i]);
            backtrack(ans, cnt, target-candidates[i], candidates, i+1);
            cnt.pop_back();
            while (i+1 < candidates.size() && candidates[i+1] == candidates[i]){
                ++i;
            }
        }
        return;
    }
public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());
        vector<vector<int>> ans;
        vector<int> cnt;
        backtrack(ans, cnt, target, candidates, 0);
        return ans;
    }
};
