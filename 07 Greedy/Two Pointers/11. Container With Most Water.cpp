class Solution {
private:
    int bruteForce(vector<int>& height) {
        int maxWater = 0;

        // Brute force Approach : O(n^2)
        for (int i = 0; i < height.size(); i++) {
            for (int j = i; j < height.size(); j++) {
                maxWater = max(min(height[i], height[j]) * (j - i), maxWater);
            }
        }

        return maxWater;
    }

int optimal(vector<int>&height){
    int i=0;
    int j=height.size()-1;

    int maxWater=0;
    while(i<j){
        int curWater=min(height[i],height[j])*(j-i);
        maxWater=max(curWater,maxWater);

        if(height[i]<=height[j]){
            i++;
        }
        else{
            j--;
        }
    }

    return maxWater;
}

public:
    int maxArea(vector<int>& height) {
        return optimal(height);
    }
};
