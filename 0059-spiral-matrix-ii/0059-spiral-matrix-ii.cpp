class Solution {
public:
    
    vector<vector<int>> generateMatrix(int n) {
        vector<vector<int>> matrix(n, vector<int>(n, 0));
        int top = 0;
        int left = 0;
        int bottom = n-1;
        int right = n-1;
        int num = 1; int total = n*n;

        
            while (left <= right && top <= bottom){
            for (int i = left; i <= right && num <= total; i++){
                matrix[top][i] = num++;
            }
            top++;
            for (int i = top; i<= bottom && num <= total ; i++){
                matrix[i][right] = num++;
            }
            right--;

            if (top <= bottom){
                for (int i = right; i >= left && num <= total; i--){
                    matrix[bottom][i] = num++;
                }
                bottom--;
            }
            if (left<=right){
                for (int i = bottom; i>= top && num <= total; i--){
                    matrix[i][left] = num++;
                }
                left++;
            }
        
        }
        return matrix;


    
    }
};