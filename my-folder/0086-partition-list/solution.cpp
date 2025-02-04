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
    ListNode* partition(ListNode* head, int x) {
        if (!head) return NULL;
        ListNode* less = new ListNode(0), *lessHead = less;
        ListNode* current = head;
        ListNode* great = new ListNode(0), *greatHead = great;
      
        while (current) {
            if (current -> val < x) {
                less->next = current;
                less = less->next;
            } else {
                great->next= current;
                great = great->next;
            }
            current = current->next;
        }
        great->next = NULL;
        less->next = greatHead->next;
    

        return lessHead->next;
    }
};
