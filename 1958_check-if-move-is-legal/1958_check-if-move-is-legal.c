class Solution {
public:
    bool checkMove(vector<vector<char>>& board, int rMove, int cMove, char color) {
        //eight directions
        vector<vector<int>> directions = { {-1,-1}, {-1,0}, {-1,+1}, {0,-1}, {0,+1}, {+1,-1}, {+1,0}, {+1,+1}};

        if(board[rMove][cMove] == 'B' || board[rMove][cMove] == 'W') return false;
        for(auto dir:directions){
            if(isValid(rMove+dir[0],cMove+dir[1]) && 
                board[rMove+dir[0]][cMove+dir[1]] != color &&
                dfs(board,color,rMove+dir[0],cMove+dir[1], dir))return true;
        }
        return false;
    }
private:
    bool isValid(int row,int col){
        return row>=0 && row<8 && col>=0 && col<8;
    }

    bool dfs(vector<vector<char>>& board,char color,int row,int col,vector<int>& dir){
        
        if(board[row][col]==color) return true; //the last one should be same color
        if(board[row][col]=='.') return false;
        //same direction to the end
        if(isValid(row+dir[0],col+dir[1]) && dfs(board,color,row+dir[0],col+dir[1],dir)){
            return true;
        }
        return false;
    }
};