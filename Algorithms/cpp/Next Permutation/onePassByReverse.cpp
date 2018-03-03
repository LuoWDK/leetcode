class Solution {
private:
    inline void swap(vector<int>& nums, int i, int j){
        int temp = nums[i];
        nums[i] = nums[j];
        nums[j] = temp;
    }
    void reverse(vector<int>& nums, int i, int j){
        while (j > i){
            swap(nums, i, j);
            --j;
            ++i;
        }
    }
public:
    void nextPermutation(vector<int>& nums) {
        int len = nums.size();
        if (len < 2)
            return;
        if (nums[len-1] > nums[len-2]){
            // If the latter is in ascending order, swap the last two elements.
            swap(nums, len-1, len-2);
            return;
        }
        else{
            // If the latter is in non-increasing order, find the start position of it.
            int i = len - 2;
            while (i >= 0 && nums[i] >= nums[i+1]){
                --i;
            }
            
            if (-1 == i){   // The whole elements in nums are non-increasing
                reverse(nums, 0, len-1);
                return;
            }
            else{   // Swap the start element with the closet element, then reorder the latter by increasing order.
                int j = len - 1;
                while (nums[j] <= nums[i]){
                    --j;
                }
                swap(nums, i, j);
                reverse(nums, i+1, len-1);
                return;
            }
        }
    }
};
