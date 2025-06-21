class Solution {
public:
    int furthestBuilding(vector<int>& heights, int bricks, int ladders) {
        int n = heights.size();
        priority_queue<int> maxHeap;
        int i = 0;
        for (; i < n - 1; i++) {

            if (heights[i + 1] <= heights[i])
                continue;

            int diff = heights[i + 1] - heights[i];

            // try to use a brick first
            if (diff <= bricks) {
                bricks -= diff;
                maxHeap.push(diff);
            } else if (ladders > 0) {
                // brick a maxPastBrick used to me so that i can pass the ladder
                // to past and use the brick here in present
                if (!maxHeap.empty()) {
                    int maxPastBrick = maxHeap.top();

                    if (diff < maxPastBrick) {
                        bricks += maxPastBrick;
                        bricks -= diff;
                        maxHeap.pop();
                        maxHeap.push(diff);
                    }
                } 
                ladders--;
            } else {
                break;
            }
        }

        return i;
    }
};
