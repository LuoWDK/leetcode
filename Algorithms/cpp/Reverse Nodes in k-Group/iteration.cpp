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
        
        ListNode* dummy = new ListNode(0);
        ListNode* tail, *tmp, *next;
        int i;
        dummy->next = head;
        head = dummy;
        while(dummy){
            tail = dummy;
            i = k;
            while(i--){
                if (tail->next)
                    tail = tail->next;                    
                else
                    return head->next;
            }
            next = dummy->next;
            i = 1;
            while(i < k){
                tmp = dummy->next;
                dummy->next = tmp->next;
                tmp->next = tail->next;
                tail->next = tmp;
                ++i;
            }
            dummy = next;
        }
        return head->next;
    }
};
