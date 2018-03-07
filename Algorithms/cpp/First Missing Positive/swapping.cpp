class Solution {
private:
    void swap(int& a, int& b){
        a ^= b;
        b ^= a;
        a ^= b;
    }
    
public:
    int firstMissingPositive(vector<int>& nums) {
        int i, len = nums.size();
        for (i = 0; i < len; ++i){
            if (i+1 == nums[i])
                continue;
            int& a = nums[i];
            while (a > 0 && a <= len && a != nums[nums[i]-1])
                swap(a, nums[nums[i]-1]);
        }
        
        for (i = 0; i < len; ++i){
            if (nums[i] != i + 1)
                return i+1;
        }
        return len + 1;
    }
};
