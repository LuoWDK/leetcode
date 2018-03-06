class Solution {
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());
        vector<vector<vector<int>>> combinations(target+1, vector<vector<int>>());
        combinations[0].push_back(vector<int>());
        for(auto& num : candidates){
            for (int j = num; j <= target; ++j){
                if (combinations[j-num].size()){
                    auto temp = combinations[j-num];
                    for (auto& i : temp){
                        i.push_back(num);
                    }
                    combinations[j].insert(combinations[j].end(), temp.begin(), temp.end());
                }
            }
        }
        return combinations[target];
    }
};
