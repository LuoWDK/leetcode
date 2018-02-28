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
    ListNode* reverseKGroup(ListNode* head, int k) {
        if (1 == k || !head)
            return head;
        
        ListNode *dummy, *tail, *tmp;
        int i;
        dummy = head;
        tail = dummy;
        i = k;
        while(--i){
            if (tail->next)
                tail = tail->next;                    
            else
                return head;
        }
        tail->next = reverseKGroup(tail->next, k);
        i = 1;
        while(i < k){
            tmp = dummy->next;
            dummy->next = tail->next;
            tail->next = dummy;
            dummy = tmp;
            ++i;
        }
        
        return tail;
    }
};
