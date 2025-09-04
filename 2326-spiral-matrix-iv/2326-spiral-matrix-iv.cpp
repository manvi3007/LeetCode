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
    vector<vector<int>> spiralMatrix(int m, int n, ListNode* head) {
        vector<vector<int>> matrix(m, vector<int>(n, -1));
        int top = 0;
        int left = 0;
        int bottom = m-1;
        int right = n-1;
        ListNode* cur = head;

        
            while (cur &&  top <= bottom && left <= right  ){
            for (int i = left; i <= right && cur; i++){
                matrix[top][i] = cur->val;
                cur = cur->next;
            }
            top++;
            for (int i = top; i<= bottom && cur ; i++){
                matrix[i][right] = cur->val;
                cur = cur->next;
            }
            right--;

            if (top <= bottom){
                for (int i = right; i >= left && cur; i--){
                    matrix[bottom][i] = cur->val;
                    cur = cur -> next;
                }
                bottom--;
            }
            if (left<=right){
                for (int i = bottom; i>= top && cur; i--){
                    matrix[i][left] = cur->val;
                    cur = cur->next;
                }
                left++;
            }
        
        }
        return matrix;
    }
};