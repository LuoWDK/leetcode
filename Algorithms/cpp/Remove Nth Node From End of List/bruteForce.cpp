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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        int len = 1;
        ListNode* dummy = new ListNode(0);
        dummy->next = head;
        while (head->next != NULL){
            ++len;
            head = head->next;
        }
        head = dummy;
        len -= n;
        ++len;
        while (--len){
            head = head->next;
        }
        head->next = head->next->next;
        return dummy->next;
    }
};
