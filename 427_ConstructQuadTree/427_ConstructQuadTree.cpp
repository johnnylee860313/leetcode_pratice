/*
// Definition for a QuadTree node.
class Node {
public:
    bool val;
    bool isLeaf;
    Node* topLeft;
    Node* topRight;
    Node* bottomLeft;
    Node* bottomRight;
    
    Node() {
        val = false;
        isLeaf = false;
        topLeft = NULL;
        topRight = NULL;
        bottomLeft = NULL;
        bottomRight = NULL;
    }
    
    Node(bool _val, bool _isLeaf) {
        val = _val;
        isLeaf = _isLeaf;
        topLeft = NULL;
        topRight = NULL;
        bottomLeft = NULL;
        bottomRight = NULL;
    }
    
    Node(bool _val, bool _isLeaf, Node* _topLeft, Node* _topRight, Node* _bottomLeft, Node* _bottomRight) {
        val = _val;
        isLeaf = _isLeaf;
        topLeft = _topLeft;
        topRight = _topRight;
        bottomLeft = _bottomLeft;
        bottomRight = _bottomRight;
    }
};
*/

//O(n^2logn)
//O(n^2)

class Solution {
public:
  Node* construct(vector<vector<int>>& grid) {    
    return dfs_construct(grid, 0, 0, grid.size());
  }
private:
  Node* dfs_construct(const vector<vector<int>>& grid, int x, int y, int n) {
    if (n == 0) return nullptr;    
    bool all_zeros = true;
    bool all_ones = true;
    for (int i = x; i < x + n; ++i)
      for (int j = y; j < y + n; ++j)
        if (grid[i][j] == 0)
          all_ones = false;
        else
          all_zeros = false;
    if (all_zeros || all_ones)
      return new Node(all_ones, true, nullptr, nullptr, nullptr, nullptr);
    
    return new Node(true, false,
                    dfs_construct(grid, x,       y,       n/2),  // topLeft
                    dfs_construct(grid, x,       y + n/2, n/2),  // topRight
                    dfs_construct(grid, x + n/2, y      , n/2),  // bottomLeft
                    dfs_construct(grid, x + n/2, y + n/2, n/2)); // bottomRight
  }
};