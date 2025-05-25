#include <bits/stdc++.h>
using namespace std;

class SquareRootDecomposition {
    vector<int> arr, block;
    int blockSize, numBlocks;

public:
    // Constructor to preprocess the array
    SquareRootDecomposition(vector<int>& input) {
        arr = input;
        int n = arr.size();
        blockSize = sqrt(n); 
        numBlocks = (n + blockSize - 1) / blockSize;
        block.assign(numBlocks, INT_MIN); // Initialize blocks with minimum values

        // Precompute block maximums
        for (int i = 0; i < n; i++)
            block[i / blockSize] = max(block[i / blockSize], arr[i]);
    }

    // Range Maximum Query (O(√N))
    int rangeMax(int l, int r) {
        int maxVal = INT_MIN;
        
        // Traverse left partial block
        while (l <= r && l % blockSize != 0) 
            maxVal = max(maxVal, arr[l++]);
        
        // Traverse full blocks
        while (l + blockSize - 1 <= r) {
            maxVal = max(maxVal, block[l / blockSize]);
            l += blockSize;
        }

        // Traverse right partial block
        while (l <= r) 
            maxVal = max(maxVal, arr[l++]);

        return maxVal;
    }

    // Point update (O(√N))
    void update(int idx, int value) {
        arr[idx] = value;
        int blockIndex = idx / blockSize;
        block[blockIndex] = INT_MIN;

        // Recompute max for the updated block
        for (int i = blockIndex * blockSize; i < min((blockIndex + 1) * blockSize, (int)arr.size()); i++)
            block[blockIndex] = max(block[blockIndex], arr[i]);
    }
};

// Driver Code
int main() {
    vector<int> arr = {1, 3, 2, 7, 9, 11, 3, 5, 0, 12, 4, 8};
    SquareRootDecomposition sqrtDecomp(arr);

    cout << "Max in range (2, 8): " << sqrtDecomp.rangeMax(1, 8) << endl;  // Output: 11
    
    // Update arr[5] = 15
    sqrtDecomp.update(5, 6);
    cout << "Max in range (2, 8) after update: " << sqrtDecomp.rangeMax(3, 5) << endl;  // Output: 9

    return 0;
}
