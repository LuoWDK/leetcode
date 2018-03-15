class Solution {
public:
    int jump(vector<int>& nums) {
        int len = nums.size();
        int i, j, mm = 0;
        int dp[nums.size()+1];
        bool flag[nums.size()+1];
        memset(flag, false, sizeof(flag));
        
        // flaging useless elements
        for (i = 0; i < len-1; ++i){
            dp[i] = len;
            if (nums[i] > mm){
                flag[i] = true;
                mm = nums[i];
            }
            --mm;
        }
        dp[len-1] = len;
        dp[0] = 0;

	// iterating reminders
        for (i = 0; i < len-1; ++i){
            if (dp[len-1] < len)
                return dp[len-1];
            if (!flag[i])// pruning useless elements
                continue;
	    // updating
            for (j = 1; j <= nums[i] && i+j < len; ++j){
                dp[i+j] = min(dp[i+j], dp[i]+1);
            }
        }
        return dp[len-1];
    }
};
