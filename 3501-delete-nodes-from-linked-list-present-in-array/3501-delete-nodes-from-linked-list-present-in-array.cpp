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
    ListNode* modifiedList(vector<int>& nums, ListNode* head) {
        ListNode * dummy=new ListNode(-1);
        map<int,int>m;
        for(auto it:nums)m[it]++;
        ListNode*p=head;
        ListNode*q=dummy;
        while(p!=NULL){
            if(!m[p->val]){
                q->next=p;
                q=q->next;
            }
            ListNode*temp=p->next;
            p->next=NULL;
            p=temp;
        }
        return dummy->next;
    }
};