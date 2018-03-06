class Solution {
private:
    int binarySearch(vector<int>& nums, int target, bool flag){
        int left = 0, mid;
        int right = nums.size();
        while (left < right){
            mid = (left + right) >> 1;
            if (nums[mid] > target || (flag && nums[mid] == target))
                right = mid;
            else
                left = mid + 1;
        }
        return left;
    }
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        vector<int> ans(2, -1);
        int leftInd = binarySearch(nums, target, true);
        if (nums.size() == leftInd || target != nums[leftInd])
            return ans;
        ans[0] = leftInd;
        ans[1] = binarySearch(nums, target, false) - 1;
        return ans;
    }
};
