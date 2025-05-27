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

    ListNode *detectCycle(ListNode *head) {
        ListNode* slow=head;
        ListNode* fast=head;

        while (fast && fast->next) {
            slow = slow->next;
            fast = fast->next->next;

            if (slow==fast) {
                slow=head;
                

                while (slow!=fast) {
                    slow=slow->next;
                    fast=fast->next;
                }
                return slow;
            }
        }
        return nullptr;
    }

    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        

        ListNode* a = headA;
        ListNode* b = headB;

        while (a!=b) {
            a = a ? a->next: headB;
            b = b? b->next: headA;
        } 
        return a;
    }
};
