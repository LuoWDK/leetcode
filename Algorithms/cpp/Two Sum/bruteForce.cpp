class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        int s_nums = nums.size();
        int i, j, temp1, temp2;
        bool flag = false;
        for (i=0; i<s_nums; ++i){
            temp1 = nums[i];
            for (j=i+1; j<s_nums; ++j){
                temp2 = nums[j];
                if (temp1+temp2 == target){
                    flag = true;
                    break;
                }
            }
            if (flag == true){
                break;
            }
        }
        vector<int> ans;
        ans.push_back(i);
        ans.push_back(j);
        return ans;
    }
};
