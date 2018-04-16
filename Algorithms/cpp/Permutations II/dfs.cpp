class Solution {
private:    
    void dfs(vector<vector<int>>& ans, vector<int> nums, vector<int>& cnt, vector<bool>& visited, int depth, int len)
    {
        if (depth == len)
        {
            ans.push_back(cnt);
            return;
        }
        
        for (int i = 0; i < len; ++i)
        {
            if (!visited[i])
            {
                if (i > 0 && nums[i] == nums[i-1] && !visited[i-1])
                    continue;
                visited[i] = true;
                cnt.push_back(nums[i]);
                dfs(ans, nums, cnt, visited, depth+1, len);
                cnt.pop_back();
                visited[i] = false;                
            }
        }
    }
    
public:
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        vector<vector<int>> ans;
        vector<int> cnt;
        vector<bool> visited(nums.size(), 0);

        sort(nums.begin(), nums.end());       
        dfs(ans, nums, cnt, visited, 0, nums.size());
        
        return ans;
    }
};
