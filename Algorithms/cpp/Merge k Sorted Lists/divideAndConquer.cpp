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
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        ListNode head(0);
        ListNode l1(0);
        ListNode l2(0);
        int len = lists.size();
        if (0 == len){
            return head.next;
        }
        int step = 1;
        while (step < len){
            for (int i = 0; i+step < len; i+=(step*2)){
                l1.next = lists[i];
                l2.next = lists[i+step];
                lists[i] = mergeTwoLists(l1.next, l2.next);
            }
            step *= 2;
        }
        return lists[0];
    }
    
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2){
        ListNode *dummy = new ListNode(0);
        ListNode *head = dummy;
        while(l1 && l2){
            if (l1->val < l2->val){
                dummy->next = l1;
                dummy = dummy->next;
                l1 = l1->next;
            }
            else{
                dummy->next = l2;
                dummy = dummy->next;
                l2 = l2->next;
            }
        }
        dummy->next = l1 ? l1 : l2;
        return head->next;
    }
};
