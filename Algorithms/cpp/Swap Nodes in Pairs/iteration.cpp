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
    ListNode* swapPairs(ListNode* head) {
        if (NULL == head || NULL == head->next)
            return head;
        ListNode* dummy = new ListNode(0);
        dummy->next = head;
        ListNode* l1 = head;
        head = dummy;
        while (l1 && l1->next){
            dummy->next = l1->next;
            l1->next = dummy->next->next;
            dummy->next->next = l1;
            dummy = dummy->next->next;
            l1 = dummy->next;
        }
        return head->next;
    }
};
