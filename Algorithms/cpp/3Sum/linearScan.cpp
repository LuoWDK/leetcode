class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> ans;
        int len = nums.size();
        if (len == 0)
            return ans;
        
        vector<int> temp;
        sort(nums.begin(), nums.end());
        int complement, left, right, sum;
        for (int i = 0; i < len; ++i){
            complement = -1 * nums[i];
            left = i + 1;
            right = len - 1;
            while(left < right){
                sum = nums[left] + nums[right];
                if (sum < complement){
                    ++left;
                }
                else if (sum > complement){
                    --right;
                }
                else{
                    temp.push_back(nums[i]);
                    temp.push_back(nums[left]);
                    temp.push_back(nums[right]);
                    ans.push_back(temp);
                    temp.clear();
                    
                    while (left + 1 < len && nums[left + 1] == nums[left])
                        ++left;
                    while (right - 1 > i && nums[right - 1] == nums[right])
                        --right;
                    ++left;
                    --right;
                }
            }
            while(i + 1 < len && nums[i+1] == nums[i]){
                ++i;
            }
        }
        return ans;
    }
};
