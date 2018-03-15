class Solution {
public:
    int jump(vector<int>& nums) {
        int len = nums.size();
        if (len < 2)
            return 0;
        int i = 0, currentPos = 0, nextPos = 0, step = 0;
        for (i = 0; i < len-1; ++i){
            nextPos = max(nextPos, nums[i]+i);// update fastest
            if (currentPos == i){
                ++step;
                currentPos = nextPos;
                if (currentPos >= len - 1)
                    return step;
            }
        }
        return step;
    }
};
