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
// class Solution {
// public:
//     ListNode* middleNode(ListNode* head) {
//         ListNode* tail = head;
//         int count = 0;
//         while(tail){
//             tail = tail->next;
//             count++;
//         }
//         if(count%2==0) count = count/2;
//         else count /= 2;
//         while(count--)
//             head = head->next;
//         return head;
//     }
// };

class Solution {
public:
    ListNode* middleNode(ListNode* head) {
        ListNode* slow = head;
        ListNode* fast = head;
        while(fast&&fast->next){
            fast = fast->next->next;
            slow = slow->next;
        }
        return slow;
    }
};
