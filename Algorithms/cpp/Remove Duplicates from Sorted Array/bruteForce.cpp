class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int len = nums.size();
        if (len < 2){
            return len;
        }
        vector <int>::iterator it = nums.begin();
        vector <int>::iterator pre = it;
        ++it;
        while (it != nums.end()){
            if (*it == *pre){
                nums.erase(it);
                it = pre;
            }
            else{
                pre = it;
            }
            ++it;
        }
        return nums.size();
    }
};
