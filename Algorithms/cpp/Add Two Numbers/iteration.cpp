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
    ListNode* addTwoNumbers(ListNode* p1, ListNode* p2) {
        ListNode* cnt = new ListNode(0);
        ListNode* ans = cnt;
        ListNode* l1 = p1;
        ListNode* l2 = p2;
        ListNode* p;
        int carry = 0;
        while (l1 || l2 || carry){
            if(l1){
                carry += l1->val;
                l1 = l1->next;
            }
            if(l2){
                carry += l2->val;
                l2 = l2->next;
            }
            p = new ListNode(carry % 10);
            cnt->next = p;
            cnt = cnt->next;
            carry /= 10;
        }
        ans = ans->next;
        return ans;
    }
};
