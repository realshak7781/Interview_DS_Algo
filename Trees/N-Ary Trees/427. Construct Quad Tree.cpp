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

    Node(bool _val, bool _isLeaf, Node* _topLeft, Node* _topRight, Node*
_bottomLeft, Node* _bottomRight) { val = _val; isLeaf = _isLeaf; topLeft =
_topLeft; topRight = _topRight; bottomLeft = _bottomLeft; bottomRight =
_bottomRight;
    }
};
*/

class Solution {
private:
    bool isSame(int rowStart, int rowEnd, int colStart, int colEnd,
                vector<vector<int>>& grid) {
        bool has1 = false;
        bool has0 = false;

        for (int i = rowStart; i < rowEnd; i++) {
            for (int j = colStart; j < colEnd; j++) {
                if (grid[i][j] == 1) {
                    has1 = true;
                }

                if (grid[i][j] == 0) {
                    has0 = true;
                }

                if (has1 && has0)
                    return false;
            }
        }
        return true;
    }

   Node* solve(int rowStart, int rowEnd, int colStart, int colEnd, vector<vector<int>>& grid) {
        if (isSame(rowStart, rowEnd, colStart, colEnd, grid)) {
            Node* node = new Node(grid[rowStart][colStart], true);
            return node;
        }

        Node* node = new Node(grid[rowStart][colStart], false);

        int midRow = (rowStart + rowEnd) / 2;
        int midCol = (colStart + colEnd) / 2;

        node->topLeft = solve(rowStart, midRow, colStart, midCol, grid);
        node->topRight = solve(rowStart, midRow, midCol, colEnd, grid);
        node->bottomLeft = solve(midRow, rowEnd, colStart, midCol, grid);
        node->bottomRight = solve(midRow, rowEnd, midCol, colEnd, grid);

        return node;
    }

public:
    Node* construct(vector<vector<int>>& grid) {
        int n = grid.size();
        return solve(0, n, 0, n, grid);
    }
};
