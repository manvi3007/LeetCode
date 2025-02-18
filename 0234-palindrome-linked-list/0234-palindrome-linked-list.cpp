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
    ListNode* reversee(ListNode* head){
        ListNode* temp = head;
        ListNode* prev = nullptr;
        
        while (temp != NULL){
            ListNode* fr = temp -> next;
            temp->next = prev;
            prev = temp;
            temp = fr;
           
        }
        return prev;
        

    }
    bool isPalindrome(ListNode* head) {
        if(head== NULL || head->next == NULL){
            return true;
        }
        ListNode* slow = head;
        ListNode* fast = head;
        while(fast ->next!= NULL && fast ->next->next != NULL){
            slow = slow->next;
            fast = fast->next->next;

        }
        ListNode* newHead = reversee(slow->next);
        ListNode* first = head;
        ListNode*  second = newHead;
        while (second != NULL){
            if (first->val != second->val){
                reversee(newHead);
                return false;


            }
            first = first->next;
            second = second->next;
            
            
        }
        reversee(newHead);
        return true;
    }
};