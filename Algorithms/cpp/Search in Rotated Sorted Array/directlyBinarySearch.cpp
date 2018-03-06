class Solution {
public:
    int search(vector<int>& nums, int target) {
        int left = 0;
        int right = nums.size() - 1;
        int mid;
        while (left < right){
            mid = (left + right) >> 1;
            if (target == nums[mid])
                return mid;
            if (nums[mid] < nums[right]){
                if (target > nums[mid] && target <= nums[right]){
                    left = mid + 1;
                }
                else{
                    right = mid;
                }
            }
            else{
                if (target > nums[mid] || target <= nums[right]){
                    left = mid + 1;
                }
                else{
                    right = mid;
                }
            }
        }
        if (left == right && target != nums[left])
            return -1;
        return right;
    }
};
