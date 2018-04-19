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
    ListNode* rotateRight(ListNode* head, int k) {
        if (NULL == head || NULL == head->next || 0 == k) {
            return head;
        }
        ListNode* tail = head;
        int count = 1;
        while (tail->next != NULL) {
            ++count;
            tail = tail->next;
        }
        tail->next = head;
        
        if (k %= (count)) {
            k = count - k;
            while (k--) {
                tail = tail->next;
            }
        }
        head = tail->next;
        tail->next = NULL;
        return head;
    }
};
