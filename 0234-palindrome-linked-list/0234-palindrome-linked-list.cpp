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
        if (!head || !head->next) return head;
        ListNode* prev = nullptr;
        ListNode* temp = head;

        while(temp  != nullptr){
            ListNode* first = temp -> next;
            temp -> next = prev;
            prev = temp;
            temp = first ;
        }
        return prev;
    }
    bool isPalindrome(ListNode* head) {
        if (!head || !head->next) return true;
        ListNode* fast = head;
        ListNode* slow = head;
        while(fast ->next != nullptr && fast -> next -> next != nullptr){
            slow = slow -> next;
            fast = fast -> next -> next;
        }

        ListNode* newHead = reversee(slow-> next);
        ListNode* sslow = newHead;
        ListNode* ffast = head;

        while(sslow != nullptr){
            
            if (sslow-> val != ffast -> val){
                reversee(newHead);
                return false;
            }
            else{
                ffast = ffast-> next;
                sslow = sslow -> next;
            }
        }
        reversee(newHead);
        return true;
    }
};