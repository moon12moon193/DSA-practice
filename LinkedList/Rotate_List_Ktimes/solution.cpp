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
    ListNode* rotateRight(ListNode* head, int k) {
        if(head==NULL){
            return NULL;
        }
        if(head->next==NULL){
            return head;
        }
        ListNode* firstNode=head;
        ListNode* temp=head;
        ListNode* t=head;
        int n=1;
        while(temp->next!=NULL){
            n++;
            temp=temp->next;
        }
        k=k%n;
        if(k==0){
            return head;
        }
        
        ListNode* lastNode=temp;
        int count=1;
        int validIndex=n-k;
        while(count<validIndex){
            t=t->next;
            count++;
        }
        ListNode* newHead=t->next;
        t->next=NULL;
        lastNode->next=firstNode;
        head=newHead;
        return newHead;

        
    }
};
