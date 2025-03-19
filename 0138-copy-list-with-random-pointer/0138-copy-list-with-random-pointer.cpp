/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    void InsertN(Node* head){
        Node* temp = head;
        while (temp != NULL){
            Node* copyy = new Node(temp -> val);
            copyy -> next = temp -> next;
            temp -> next = copyy;
            temp = temp -> next -> next;
        }
        
    }
    void random (Node* head){
        Node* temp = head;
        while (temp != NULL){
            Node* copyy = temp -> next;
            if (temp -> random != NULL){
                copyy -> random = temp -> random -> next;

            }
            else {
               copyy -> random = nullptr;
            }
             temp = temp -> next-> next;
        }
    
    }
    Node* linki(Node* head){
        Node* dNode = new Node(-1);
        Node* res = dNode;
        Node* temp = head;
        while (temp != NULL){
            res-> next = temp -> next;
            temp -> next = temp -> next -> next;
            res = res -> next;
            temp = temp -> next;
        }
        return dNode ->next;
    }

    Node* copyRandomList(Node* head) {
       if (!head){
        return nullptr;
       }
       InsertN(head);
       random (head);
       return linki(head);
    }
};