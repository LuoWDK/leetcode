class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        int len = nums.size();
        int complement, left, right, temp;
        int ans = nums[0] + nums[1] + nums[2];
        
        if(len == 3){
            return ans;
        }
        
        sort(nums.begin(), nums.end());
        
        for (int i = 0; i < len; ++i){
            complement = target - nums[i];
            left = i + 1;
            right = len - 1;
            while (left < right){
                temp = nums[left] + nums[right];
                if (abs(ans - target) > abs(complement - temp)){
                    ans = temp + nums[i];
                }
                if (temp < complement){
                    ++left;
                }
                else if (temp > complement){
                    --right;
                }
                else{
                    break;
                }
            }
        }
        return ans;
    }
};
