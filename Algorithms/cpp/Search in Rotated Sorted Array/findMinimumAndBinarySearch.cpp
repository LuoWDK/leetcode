class Solution {
private:
    int binarySearch(vector<int>& nums, int left, int right, int target){
        int mid;
        while (left <= right){
            mid = (left + right) >> 1;
            if (target == nums[mid])
                return mid;
            else if (target < nums[mid]){
                right = mid - 1;
            }
            else{
                left = mid + 1;
            }
        }
        return -1;
    }
    int findMin(vector<int>& nums){
        int left = 0, right = nums.size() - 1, mid;
        while (right > left){
            mid = (left + right) >> 1;
            if (nums[mid] < nums[right]){
                right = mid;
            }
            else{
                left = mid + 1;
            }
        }
        return right;
    }
public:
    int search(vector<int>& nums, int target) {
        int len = nums.size();
        if (0 == len)
            return -1;
        int minInd = findMin(nums);
        if (target == nums[minInd])
            return minInd;
        else{
            return target <= nums[len-1] ? binarySearch(nums, minInd, len-1, target) : binarySearch(nums, 0, minInd-1, target);
        }
    }
};
