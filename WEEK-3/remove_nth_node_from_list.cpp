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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        int count = 0;
        ListNode* slow = head;
        ListNode* fast = head;
        ListNode* prev = nullptr;
        while (fast) {
            fast = fast -> next;
            if (count >= n) {
                prev = slow;
                slow = slow -> next;
            }
            count ++;
        }
        if (prev) {
            prev -> next = slow -> next;
            return head;
        }
        else return slow -> next;

        
    }
};