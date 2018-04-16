class Solution {
private:
    bool find(vector<int> nums, int start, int end, int key)
    {
        for (int k = start; k < end; ++k)
        {
            if (key == nums[k])
                return true;
        }
        return false;
    }
    
    void recursion(vector<vector<int>>& ans, vector<int>& nums, int depth, int len)
    {
        if (depth == len)
        {
            ans.push_back(nums);
            return;
        }
        
        for (int i = depth; i < len; ++i)
        {
            if (!find(nums, depth, i, nums[i]))
            {
                swap(nums[i], nums[depth]);
                recursion(ans, nums, depth+1, len);
                swap(nums[i], nums[depth]);
            }
        }
    }
    
public:
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        // sort(nums.begin(), nums.end());
        vector<vector<int>> ans;
        recursion(ans, nums, 0, nums.size());
        
        return ans;
    }
};
