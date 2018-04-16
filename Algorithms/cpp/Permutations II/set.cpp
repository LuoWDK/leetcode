class Solution {
private:    
    void recursion(set<vector<int>>& ans, vector<int>& nums, int depth, int len)
    {
        if (depth == len)
        {
            ans.insert(nums);
            return;
        }
        
        for (int i = depth; i < len; ++i)
        {
            swap(nums[i], nums[depth]);
            recursion(ans, nums, depth+1, len);
            swap(nums[i], nums[depth]);
        }
    }
    
public:
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        set<vector<int>> ans;
        recursion(ans, nums, 0, nums.size());
        
        return vector<vector<int>>(ans.begin(), ans.end());
    }
};
