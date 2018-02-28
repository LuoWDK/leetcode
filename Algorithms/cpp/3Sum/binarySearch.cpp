class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> ans;
        vector<int> temp;
        int len = nums.size();
        if (len < 3){
            return ans;
        }
        
        multiset <int> ordered;
        multiset <int>::iterator it1, it2, it3;
        for (int i = 0; i < len; ++i){
            ordered.insert(nums[i]);
        }
        if (ordered.count(0) > 2){
            for(int i = 0; i < 3; ++i){
                temp.push_back(0);
            }
            ans.push_back(temp);
            temp.clear();
        }
        
        it1 = ordered.begin();
        int complement = 0;
        long long int pre = (*it1) - 1;
        for (; it1 != ordered.end(); ++it1){
            if (*it1 >= 0)
                break;
            if (*it1 == pre){
                pre = *it1;
                continue;
            }
            
            it2 = it1;
            ++it2;
            while (it2 != ordered.end()){
                complement = *it1 + *it2;
                complement *= -1;
                if (complement < *it2){
                    break;
                }
                if (complement > *it2){
                    it3 = ordered.find(complement);
                    if (it3 == ordered.end()){
                        ++it2;
                        continue;
                    }
                }
                else{
                    if (ordered.count(complement) == 1){
                        ++it2;
                        continue;
                    }
                }
                temp.push_back(*it1);
                temp.push_back(*it2);
                temp.push_back(complement);
                ans.push_back(temp);
                temp.clear();
                it2 = ordered.upper_bound(*it2);
            }
            pre = *it1;
        }
        return ans;
    }
};
