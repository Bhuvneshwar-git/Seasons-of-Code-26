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


    void reorderList(ListNode* head) {
        ListNode* slow = head;
        ListNode* fast = head;
        while (fast && fast -> next) {
            fast = fast -> next -> next;
            if (fast) slow = slow -> next;
            
        }
        ListNode* half = slow -> next;
        slow -> next = nullptr;
        ListNode* second = reverseList(half);
        ListNode* first = head -> next;
        int turn = -1;
        while (first || second) {
            if (turn == -1) {
                head -> next = second;
                head = head -> next;
                second = second -> next;
                turn *= -1;
            }
            else {
                head -> next = first;
                head = head -> next;
                first = first -> next;
                turn *= -1;
            }
        }    
    }
};