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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2, int carry = 0) {
        if (l1){
            carry += l1->val;
            l1 = l1->next;
        }
        if (l2){
            carry += l2->val;
            l2 = l2->next;
        }
        ListNode* p = new ListNode(carry%10);
        carry /= 10;
        if (l1 || l2){
            p->next = addTwoNumbers(l1, l2, carry);
        }
        else if(carry){
            p->next = new ListNode(carry);
        }
        return p;
    }
};
