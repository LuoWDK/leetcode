class Solution {
public:
    int trap(vector<int>& height) {
        int len = height.size();
        if (!len)
            return 0;
        int i, ans = 0;
        vector<int> leftDP(len);
        vector<int> rightDP(len);
        leftDP[0] = height[0];
        for (i = 1; i < len; ++i){
            leftDP[i] = max(height[i], leftDP[i-1]);
        }
        rightDP[len-1] = height[len-1];
        for (i = len-2; i >= 0; --i){
            rightDP[i] = max(height[i], rightDP[i+1]);
        }
        for (i = 0; i < len; ++i){
            ans += min(leftDP[i], rightDP[i]) - height[i];
        }
        return ans;
    }
};
