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
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        ListNode* curr = new ListNode();
        ListNode* head = curr;
        while(l1 && l2){
            cout<<curr->val;
            if(l1->val > l2->val){
                curr->next = l2;
                l2 = l2->next;
            }else{
                curr->next = l1;
                l1 = l1->next;
            }
            curr = curr->next;
        }
        if(l1) curr->next = l1;
        if(l2) curr->next = l2;
        return head->next;
    }
};