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
    ListNode* reverseList(ListNode* head) {
        ListNode* curr = head;
        ListNode* prev = nullptr;
        ListNode* next = nullptr;
        while (curr) {
            next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }
        return prev;
        
    }

    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode* end = head;
        ListNode* start = head;
        for (int i = 1; end && i <= k-1; i++) end = end -> next;
        if (!end) return head;
        else {
            ListNode* ahead = end -> next;
            end -> next = nullptr;
            ListNode* reversed = reverseList(start);
            ListNode* newhead = reversed;
            for (int i = 1; i <= k-1; i++) reversed = reversed -> next;
            reversed -> next = reverseKGroup(ahead, k);
            return newhead;
        }


        
    }
};