//   https://leetcode.com/problems/add-two-numbers/submissions/
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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* res = new ListNode(-1);
        ListNode* head = res;
        int carry = 0,sum;
        while(l1 || l2 || carry)
        {
        	int val1 = 0,val2 = 0;
        	res->next = new ListNode();
        	res = res->next;
        	if(l1){	val1 = l1->val; l1=l1->next; }
        	if(l2){	val2 = l2->val; l2 = l2->next; }

        	sum  = val1 + val2 + carry;
        	res->val = sum%10;
        	carry = sum/10;
        	

        }
        return head->next;

        
    }
};