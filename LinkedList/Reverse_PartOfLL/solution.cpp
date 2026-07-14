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
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        if(left==right){
            return head;
        }
        ListNode* before=NULL;
        ListNode* t=head;
        int position=1;
        while(position<left){
            before=t;
            t=t->next;
            position++;
            continue;
        }
        int times=right-left+1;
        int number=1;
        ListNode* prev=NULL;
        ListNode* curr=t;
        while(number<=times){
            ListNode* nes=curr->next;
            curr->next=prev;
            prev=curr;
            curr=nes;
            
            number++;
            
        }
        t->next=curr;
        if(before!=NULL){
            before->next=prev;
            return head;
        }else{
            return prev;
        }
        
    }
};
