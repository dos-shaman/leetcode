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
    ListNode* partition(ListNode* head, int x) {
        if(head ==NULL)
        return head;
        ListNode* curr = head;
        vector<int>a,b;
        while(curr!=NULL)
        {
            if(curr -> val <x)
            a.push_back(curr -> val);
            else
            b.push_back(curr -> val);
            curr=curr->next;
        }
        ListNode * temp1= new ListNode();
        ListNode* t1=temp1;
        ListNode * temp2= new ListNode();
        ListNode* t2=temp2;
        int i=0;
        while(i<a.size())
        {
            int x=a[i];
            ListNode* new_node=new ListNode(x);
            t1 ->next=new_node;
            t1= t1 ->next;
            i++;
        }
         i=0;
        while(i<b.size())
        {
            int x=b[i];
            ListNode* new_node=new ListNode(x);
            t2 ->next=new_node;    
            t2=t2 ->next;
            i++;
        }
        t1 ->next=temp2 ->next;
        return temp1 -> next;
    }
};