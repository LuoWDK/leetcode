class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        vector<vector<int>> ans;
        int len = nums.size();
        if (len < 4){
            return ans;
        }
        sort(nums.begin(), nums.end());
        
        int complement, left, right, temp;
        vector<int> cnt;
        for (int i = 0; i < len; ++i){
            if (nums[i] + nums[len-1] + nums[len-2] + nums[len-3] < target){
                continue;
            }
            if (i+3 < len && nums[i] + nums[i+1] + nums[i+2] + nums[i+3] > target){
                break;
            }
            for (int j = i+1; j < len; ++j){
                complement = target - nums[i] - nums[j];
                left = j + 1;
                right = len - 1;
                while (left < right){
                    temp = nums[left] + nums[right];
                    if (temp < complement){
                        ++left;
                    }
                    else if (temp > complement){
                        --right;
                    }
                    else{
                        cnt.push_back(nums[i]);
                        cnt.push_back(nums[j]);
                        cnt.push_back(nums[left]);
                        cnt.push_back(nums[right]);
                        ans.push_back(cnt);
                        cnt.clear();
                        while (left+1 < len && nums[left] == nums[left+1]){
                            ++left;
                        }
                        while (right-1 > j && nums[right-1] == nums[right]){
                            --right;
                        }
                        --right;
                        ++left;
                    }
                }
                while (j+1 < len && nums[j+1] == nums[j])
                    ++j;
            }
            while (i+1 < len && nums[i+1] == nums[i])
                ++i;
        }
        return ans;
    }
};
