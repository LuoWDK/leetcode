class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        int left = 0, mid;
        int right = nums.size();
        while (left < right){
            mid = (left + right) >> 1;
            if (target == nums[mid])
                return mid;
            else if (nums[mid] > target)
                right = mid;
            else
                left = mid + 1;
        }
        return right;
    }
};
