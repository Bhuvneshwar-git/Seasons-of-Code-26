/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        ListNode* a = list1;
        ListNode* b = list2;
        ListNode* dummy = new ListNode();
        ListNode* dhead = dummy;

        while (a || b) {
            int x = a ? a->val : 101;
            int y = b ? b->val : 101;

            if (x < y) {
                dhead -> next = a;
                dhead = dhead -> next;
                a = a -> next;
            }
            else {
                dhead -> next = b;
                dhead = dhead -> next;
                b = b -> next;
            }

        }
        return dummy->next;
        
    }
};