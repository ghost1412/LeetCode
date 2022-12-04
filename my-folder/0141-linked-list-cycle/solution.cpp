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
    bool hasCycle(ListNode *head) {
        if (head == NULL || head->next == NULL) return false;
        ListNode* curr = head, *next = head->next;
        while(next && next->next) {
            if (curr == next) return true;
            curr = curr->next;
            next = next->next->next;
        }
        return false;
    }
};
