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
        int count = 0;
        while (tail->next != NULL) {
            ++count;
            tail = tail->next;
            if (count == k)
            {
                break;
            }
        }

        ListNode* newTail;
        if (count == k) {
            newTail = head;
            while(tail->next != NULL)
            {
                newTail = newTail->next;
                tail = tail->next;
            }
            tail->next = head;
        }
        else {
            k %= (count+1);
            if (0 == k) {
                return head;
            }
            tail->next = head;
            newTail = tail;
            k = count + 1 - k;
            while (k--) {
                newTail = newTail->next;
            }
        }
        head = newTail->next;
        newTail->next = NULL;
        return head;
    }
};
