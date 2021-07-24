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
    ListNode* reverse(ListNode* node){
        ListNode* prev = NULL, *next = NULL, *head = node;
        while(head!=NULL){
            next = head->next;
            head->next = prev;
            prev = head;
            head = next;
        }
        return prev;
    }
    
    ListNode* newNode(int data){
        ListNode* node = new ListNode();
        node->val = data;
        node->next = NULL;
        return node;
    }
    
    ListNode* add(ListNode* l1, ListNode* l2){
        ListNode* sum_head = NULL, *prev;
        ListNode* res = sum_head;
        int a, b, c = 0;
        while(l1 != NULL || l2 != NULL){
            int sum_val = c + (l1?l1->val:0) + (l2?l2->val:0);
            c = (sum_val>=10) ? 1:0;
            sum_val = sum_val%10;
            ListNode* sum_node = newNode(sum_val);          
            if(res == NULL){
                res = sum_node;
            }
            else{
                prev->next = sum_node;
            }            
            prev = sum_node;
            if(l1)
                l1 = l1->next;
            if(l2)
                l2 = l2->next;
        }
        if(c > 0){
            prev->next = newNode(c);
        }
        return res;
    }
    
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        return add(l1, l2);
    }
};
