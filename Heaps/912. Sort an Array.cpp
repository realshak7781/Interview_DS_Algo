class Solution {
private:
    void heapify(int i, int n, vector<int>& nums) {
        int idx = i;
        int leftChild = 2 * i + 1;
        int rightChild = 2 * i + 2;

        // max heap logic ,the max element will be at nums[0]
        if (leftChild < n && nums[idx] < nums[leftChild]) {
            idx = leftChild;
        }

        if (rightChild < n && nums[idx] < nums[rightChild]) {
            idx = rightChild;
        }

        if (idx != i) {
            swap(nums[idx], nums[i]);
            heapify(idx, n, nums);
        }
    }

    void heapSort(vector<int>& nums, int n) {
        int size = n;

        while (size > 1) {
            swap(nums[0], nums[size - 1]);
            size--;
            heapify(0,size,nums);
        }
    }

public:
    vector<int> sortArray(vector<int>& nums) {
        // WE WILL DO THE PROBLEM USING HEAP SORT LOGI
        int n = nums.size();
        for (int i = n / 2 - 1; i >= 0; i--) {
            heapify(i, n, nums);
            // this is mathematically o(n ) time: BUILDING THE HEAP
        }

        // nOW HEAP SORT LOIC
        heapSort(nums, n);
        // o(nlogn)

        return nums;
    }
};
