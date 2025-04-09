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
    ListNode* sortList(ListNode* head) {
        if (head == NULL || head->next == NULL) return head;

        ListNode* slow = head;
        ListNode* fast = head;
        ListNode* tail = NULL;

        while (fast != NULL && fast->next != NULL) {
            tail = slow;
            slow = slow->next;
            fast = fast->next->next;
        }

        tail->next = NULL;

        ListNode* first = sortList(slow);
        ListNode* second = sortList(head);

        return mergeList(first, second);
    }

    ListNode* mergeList(ListNode* first, ListNode* second) {
        ListNode* sorted = new ListNode(0);
        ListNode* curr = sorted;

        while (first && second) {
            if (first->val <= second->val) {
                curr->next = first;
                first = first->next;
            } else {
                curr->next = second;
                second = second->next;
            }
            curr = curr->next;
        }

        if (first) {
            curr->next = first;
        }

        if (second) {
            curr->next = second;
        }
        return sorted->next;
    }
};
