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
    ListNode* findK(ListNode* temp, int k) {
        k -= 1;
        while (temp != NULL && k > 0) {
            k--;
            temp = temp->next;
        }
        return temp;
    }

    ListNode* reverseL(ListNode* head) {
        ListNode* temp = head;
        ListNode* prev = nullptr;
        while (temp != NULL) {
            ListNode* front = temp->next;
            temp->next = prev;
            prev = temp;
            temp = front;
        }
        return prev;
    }

    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode* temp = head;
        ListNode* nextNode = nullptr;
        ListNode* prevNode = nullptr;

        while (temp != NULL) {  // Fix: Changed temp->next != NULL to temp != NULL
            ListNode* kthNode = findK(temp, k);
            if (kthNode == NULL) {
                if (prevNode) {
                    prevNode->next = temp;
                }
                break;
            }

            nextNode = kthNode->next;
            kthNode->next = nullptr;
            reverseL(temp);

            if (temp == head) {
                head = kthNode;  // Fix: Updated head instead of kthNode
            } else {
                prevNode->next = kthNode;
            }

            prevNode = temp;
            temp->next = nextNode;
            temp = nextNode;
        }
        return head;
    }
};
