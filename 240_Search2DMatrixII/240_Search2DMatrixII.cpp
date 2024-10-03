// O(log(m * n))
/*Start form The leftist bottom number, 
    if the target is greater than it , goes right
    if the target is less than it, goes up*/
class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int row = matrix.size()-1;
        int col = 0;
        int m = matrix.size()-1;
        int n = matrix[0].size()-1;

        if (target < matrix[0][0] || target > matrix[m][n])return false;

        while(true){
            if (target < matrix[row][col])--row;
            else if (target > matrix[row][col])++col;
            else return true;
            
            if (row < 0 || col > n)break;
        }
        return false;
    }
};