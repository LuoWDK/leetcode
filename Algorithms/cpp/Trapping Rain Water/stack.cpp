class Solution {
public:
    int trap(vector<int>& height) {
        int len = height.size();
        stack<int> st;
        int i, ans = 0, top, dist, hei;
        for (i = 0; i < len; ++i){
            while (!st.empty() && height[st.top()] < height[i]){
                top = st.top();
                st.pop();
                if (st.empty())
                    break;
                dist = i - st.top() - 1;
                hei = min(height[i], height[st.top()]) - height[top];
                ans += hei * dist;
            }
            st.push(i);
        }
        return ans;
    }
};
