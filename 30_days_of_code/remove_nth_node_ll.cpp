//   https://leetcode.com/problems/remove-nth-node-from-end-of-list/
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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        
        ListNode *t = head,*nth=NULL;
        int i=0;
      
        while(t->next)
        {
            t = t->next;
            i++;
            if(i==n)    nth = head;
            if(i>n)     nth = nth->next;
            
        }
        if(nth==NULL)   return head->next;
        nth->next = nth->next->next;
        return head;
    }
    
};