/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 c,t
 a b c d e
 */
class Solution {
public:
    ListNode* reverseList(ListNode* head){
        ListNode* curr = head, *temp = NULL, *temp1 = NULL;
        while(curr != NULL){
            temp1 = curr->next;
            curr->next = temp;
            temp = curr;
            curr = temp1;
        }
        return temp;
    }
    
    bool isPalindrome(ListNode* head) {
        ListNode* slow = head;
        ListNode*fast = head;
        if(head == NULL) return 1;
        while(fast != NULL && fast->next != NULL){
            fast = fast->next->next;
            slow = slow->next;
        }
        ListNode* rev = reverseList(slow);
        while(head!=NULL&&rev!=NULL){
            if(head->val != rev->val)
                return 0;
            rev = rev->next;
            head = head->next;
        }
        return 1;
    }
};
