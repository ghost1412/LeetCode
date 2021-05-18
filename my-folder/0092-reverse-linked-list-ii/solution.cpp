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
    ListNode* reverse(ListNode* head){
        ListNode* curr = head, *prev = NULL;
        while(curr != NULL){
            ListNode* temp = curr->next;
            curr->next = prev;
            prev = curr;
            curr = temp;
        }
        return prev;
    }
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        int i = 0;
        ListNode* curr = head, *nex = NULL, *prev = NULL;
        ListNode* st = NULL, *en = NULL;
        while(curr!=NULL){
            if(i == left - 2){
                prev = curr;
            }else
            if(i == left-1){
                st = curr;
            }
            else if(i == right-1){
                nex = curr->next;
                curr->next = NULL;
                ListNode* reverseNode = reverse(st);
                if(prev != NULL)
                    prev->next = reverseNode;
                else
                    head = reverseNode;
                ListNode* temp = reverseNode;
                while(temp->next != NULL){
                    en = temp;
                    temp = temp->next;
                }
                temp->next = nex;
            }
            i++;
            curr = curr->next;
        }
        return head;
    }
};
