class Solution {
public:
    int maxArea(vector<int>& height) {
        int l = 0, r = height.size() - 1, ans = 0, tempArea;
        while(l < r){
            if (height[l] < height[r]){
                tempArea = (r - l) * height[l];
                ++l;
            }
            else{
                tempArea = (r - l) * height[r];
                --r;
            }
            ans = max(ans, tempArea);
        }
        return ans;
    }
};
