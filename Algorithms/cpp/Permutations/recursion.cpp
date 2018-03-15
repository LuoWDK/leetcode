class Solution {
private:
    // void swap(vector<int>& cnt, int a, int b){
    //     cnt[a] = cnt[a] - cnt[b];
    //     cnt[b] = cnt[a] + cnt[b];
    //     cnt[a] = cnt[a] - cnt[b];
    // }
    void solution (vector<int>& nums, vector<vector<int>>& ans, int depth){
        if (nums.size() == depth){
            ans.push_back(nums);
            return;
        }
        for (int i = depth; i < nums.size(); ++i){
            swap(nums[depth], nums[i]);
            solution(nums, ans, depth+1);
            swap(nums[depth], nums[i]);
        }
    }
public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> ans;
        solution(nums, ans, 0);
        return ans;
    }
};
