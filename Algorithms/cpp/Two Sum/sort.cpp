struct node{
    int id;
    int val;
};

bool comp(const node &N1, const node &N2){
    return N1.val < N2.val;
}

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector <int> ans;
        node N[nums.size()];
        int i, l, r;
        int s_nums = nums.size();
        node temp;
        for(i=0; i<s_nums; ++i){
            N[i].id = i;
            N[i].val = nums[i];
        }
        sort(N, N+s_nums, comp);
        l = 0;
        r = s_nums-1;
        while(true){
            if(N[l].val + N[r].val == target){
                break;
            }
            else if(N[l].val + N[r].val < target){
                ++l;
            }
            else if(N[l].val + N[r].val > target){
                --r;
            }
        }
        ans.push_back(min(N[l].id, N[r].id));
        ans.push_back(max(N[l].id, N[r].id));
        return ans;
    }
};
