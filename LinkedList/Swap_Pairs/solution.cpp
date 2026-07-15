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
    void reverse(ListNode* head, int k) {
        ListNode* curr = head;
        ListNode* prev = NULL;
        int number = 1;
        while (number <= k) {
            ListNode* nex = curr->next;
            curr->next = prev;
            prev = curr;
            curr = nex;
            number++;
        }
    }
    ListNode* swapPairs(ListNode* head) {
        ListNode* left = head;
        ListNode* prevNode = NULL;
        ListNode* right;
        ListNode* res=NULL;
        ListNode* nextLeft;
        int k = 2;
        while (true) {
            right = left;
            for (int i = 0; i < k - 1; i++) {
                if (right != NULL) {
                    right = right->next;
                }
            }
            if (right != NULL) {
                 nextLeft = right->next;

                reverse(left, k);
                if (prevNode != NULL) {
                    prevNode->next = right;
                }
                prevNode = left;
                
                left = nextLeft;
                if (res == NULL) {
                    res = right;
                }
            } else {
                if (prevNode != NULL) {
                    prevNode->next = left;
                }
                if (res == NULL) {
                    res = left;
                }
                break;
            }
        }
        return res;
    }
};
