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
    struct comp{
        bool operator()(const ListNode* l1, const ListNode* l2){
            return l1->val > l2->val;
        }
    };
    
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        int len = lists.size();
        if (0 == len){
            return NULL;
        }
        
        ListNode *dummy = new ListNode(0);
        ListNode *ans = dummy;
        priority_queue<ListNode*, vector<ListNode*>, comp> pq;
        for (int i = 0; i < len; ++i){
            if (lists[i]){
                pq.push(lists[i]);
            }
        }
        if (pq.empty())
            return NULL;
        
        dummy = pq.top();
        pq.pop();
        ans = dummy;
        if (dummy->next){
            pq.push(dummy->next);
        }
        while (!pq.empty()){
            dummy->next = pq.top();
            pq.pop();
            dummy = dummy->next;
            if (dummy->next){
                pq.push(dummy->next);
            }
        }
        return ans;
    }
};
