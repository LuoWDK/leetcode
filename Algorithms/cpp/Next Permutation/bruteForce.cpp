class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int len = nums.size();
        if (len < 2)
            return;
        if (nums[len-1] > nums[len-2]){
            // If the latter is in ascending order, swap the last two elements.
            swap(nums[len-1], nums[len-2]);
            return;
        }
        else{
            // If the latter is in non-increasing order, find the start position of it.
            int i = len - 2;
            while (i >= 0 && nums[i] >= nums[i+1]){
                --i;
            }
            
            if (-1 == i){   // The whole elements in nums are non-increasing
                sort(nums.begin(), nums.end());
                return;
            }
            else{   // Swap the start element with the closet element, then reorder the latter by increasing order.
                int j = len - 1;
                vector <int>::iterator it = nums.end();
                --it;
                while (nums[j] <= nums[i]){
                    --j;
                    --it;
                }
                swap(nums[i], nums[j]);
                while (j != i){
                    --j;
                    --it;
                }
                ++it;
                sort(it, nums.end());
                return;
            }
        }
    }
};
