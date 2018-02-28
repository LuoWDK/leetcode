class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map <int, int> nodes;
        vector <int> ans;
        int length = nums.size();
        int complement, key;
        for(int i=0; i<length; ++i){
            key = nums[i];
            complement = target - key;
            if (nodes.find(complement) != nodes.end()){
                ans.push_back(nodes[complement]);
                ans.push_back(i);
                return ans;
            }
            nodes[key]=i;
        }
    }
};
