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
    ListNode* reverse(ListNode* l){
        
        ListNode* pre=NULL,*curr=l,*forw=l;
        
        while(forw!=NULL){
            
            forw=forw->next;
            curr->next=pre;
            pre=curr;
            curr=forw;
        }
        return pre;
        
    }
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        
        l1=reverse(l1);
        l2=reverse(l2);
        ListNode *l3,*pre=NULL;
        int carry=0;
        while(l1!=NULL || l2!=NULL || carry!=0){
            int sum=carry;
            if(l1!=NULL)   {
                sum+=l1->val;
                l1=l1->next;
            }
            if(l2!=NULL) {
                sum+=l2->val;
                l2=l2->next;
            }
            
            if(sum>9){
                carry=sum/10;
                sum=sum%10;
                
            }
            else carry=0;
         
            
            ListNode* curr=new ListNode(sum);
            curr->next=pre;
            pre=curr;
            
            
        }
        
      //  pre=reverse(pre);
         
        return pre;    
        }
    
};