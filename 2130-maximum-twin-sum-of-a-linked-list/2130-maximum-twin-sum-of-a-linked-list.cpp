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
    ListNode*reverse(ListNode*x){
        ListNode*prev=NULL;
        ListNode*curr=x;
        ListNode*nxt;
        while(curr!=NULL){
            nxt=curr->next;
            curr->next=prev;
            prev=curr;
            curr=nxt;
        }
        return prev;
    }
    int pairSum(ListNode* head) {
        int maxi=INT_MIN;
        ListNode*fast=head;
        ListNode*slow=head;
        while(fast->next!=NULL and fast->next->next!=NULL){
            slow=slow->next;
            fast=fast->next->next;
        }
        slow=slow->next;
        slow=reverse(slow);
        fast=head;
        while(slow!=NULL){
            int x=slow->val;
            int y=fast->val;
            maxi=max(maxi,x+y);
            slow=slow->next;
            fast=fast->next;
        }
        return maxi;
    }
};