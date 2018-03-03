class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int len = nums.size();
        int i = 0;
        while (i < len){
            if (val == nums[i]){
                nums[i] = nums[len-1];
                --len;
            }
            else{
                ++i;
            }
        }
        return len;
    }
};
