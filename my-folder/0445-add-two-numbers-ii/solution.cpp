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
    ListNode* reverseList(ListNode* l){
        ListNode* curr = l, *prev = NULL;
        while(curr!=NULL){
            ListNode* temp = curr->next;
            curr->next = prev;
            prev = curr;
            curr = temp;
        }
        return prev;
    }
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        l1 = reverseList(l1);
        l2 = reverseList(l2);
          int carry=0 , sum=0;
        ListNode* start = NULL;
        ListNode* end = NULL;
        
        while(l1 || l2)
        {
            int a = (l1!=NULL) ? l1->val : 0;
            int b = (l2!=NULL) ? l2->val : 0;
            sum = carry+a+b;
            carry = (sum>9)?1:0;
            sum = sum%10;
            if(!start)
            {
                start = new ListNode(sum);
                end = start;
            }
            else
            {
                end->next=new ListNode(sum);
                end=end->next;
            }
            if(l1)
            {
                l1=l1->next;
            }
            if(l2)
            {
                l2=l2->next;
            }
        }
        if(carry>0)
            end->next = new ListNode(carry);
        start = reverseList(start);
        return start;   
    }
};
