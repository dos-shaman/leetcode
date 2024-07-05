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
    vector<int> nodesBetweenCriticalPoints(ListNode* head) {
        ios_base::sync_with_stdio(false);cin.tie(0),cout.tie(0);
        ListNode *prev=head,*curr=head->next;
        int first=-1,last=-1,mini=INT_MAX,midd=-1,count=0;
        if(curr==NULL)return {-1,-1};
        while(curr->next!=NULL){
            count++;
            if(prev->val<curr->val && curr->val>curr->next->val
                 || (prev->val>curr->val && curr->val<curr->next->val)){
                    if(first==-1){
                        first=count;
                        midd=count;
                    }else{
                        last=count;
                        mini=min(mini,last-midd);
                        midd=count;
                    }
            }
            prev=prev->next;
            curr=curr->next;
        }
        int maxi=last-first>0?last-first:-1;
        mini=mini==INT_MAX?-1:mini;
        return {mini,maxi};
    }
};