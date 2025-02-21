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


    int pairSum(ListNode* head) {
        int i = 0;
        ListNode* slow = head, *fast = head;

        while (fast != NULL && fast->next != NULL) {
            slow = slow->next;
            fast = fast->next->next;
        }

        ListNode* next = NULL, *prev = NULL;

        while(slow) {
            next = slow->next;
            slow->next = prev;
            prev = slow;
            slow = next;
        }
        int maxPair = INT_MIN;
        while(prev) {
            maxPair = max(maxPair, prev->val+head->val);
            prev = prev -> next;
		    head = head -> next;
        }
        return maxPair;

    }
};
