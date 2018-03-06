class Solution {
private:
    void backtrack(vector<vector<int>> &ans, vector<int> &cnt, vector<int>& candidates, int target, int index){
        if (!target){
            ans.push_back(cnt);
            return;
        }
        for (int i = index; i < candidates.size() && candidates[i] <= target; ++i){
            cnt.push_back(candidates[i]);
            backtrack(ans, cnt, candidates, target-candidates[i], i);
            cnt.pop_back();
        }
    }
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());
        vector<int> cnt;
        vector<vector<int>> ans;
        backtrack(ans, cnt, candidates, target, 0);
        return ans;
    }
};
