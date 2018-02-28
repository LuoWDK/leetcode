/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    static bool comp(ListNode* l1, ListNode* l2){
        return l1->val > l2->val;
    }
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        int len = lists.size();
        if (0 == len)
            return NULL;
        
        ListNode* dummy = new ListNode(0);
        ListNode* ans = dummy;
        vector <ListNode *> vec;
        for (int i = 0; i < len; ++i){
            if (lists[i]){
                vec.push_back(lists[i]);
            }
        }
        len = vec.size();
        if (0 == len)
            return NULL;
        
        make_heap(vec.begin(), vec.end(), comp);
        while (!vec.empty()){
            dummy->next = vec.front();
            pop_heap(vec.begin(), vec.end(), comp)         ;
            vec.pop_back();
            dummy = dummy->next;
            if (dummy->next){
                vec.push_back(dummy->next);
                push_heap(vec.begin(), vec.end(), comp);
            }
        }
        return ans->next;
    }
};
