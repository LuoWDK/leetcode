class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int len = nums.size();
        int i = 0, j = 0;
        while (j < len){
            if (val != nums[j]){
                nums[i++] = nums[j];
            }
            ++j;
        }
        return i;
    }
};
