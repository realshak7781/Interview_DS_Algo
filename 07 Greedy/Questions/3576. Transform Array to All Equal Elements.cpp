class Solution {
public:
    bool canMakeEqual(vector<int>& nums, int k) {
        // appproach:
        // try to convert all -1 to 1 and count steps = difference between
        // indices do the same for 1 to -1; we will store the indices of all neg
        // ones in an array and count steps pair wise steps=difference in indices
        // also if size of indices array is odd not possible; do the same for 1
        // --> -1

        int n = nums.size();
        vector<int> negIdx;
        for (int i = 0; i < n; i++) {
            if (nums[i] == -1) {
                negIdx.push_back(i);
            }
        }

        bool isPossible = false;
        int steps1=INT_MAX;
        if (negIdx.size() % 2 == 0) {
            isPossible = true;
            steps1=0;
            int i=0;
            while(i<negIdx.size()){
                steps1+= (negIdx[i+1]-negIdx[i]);
                i+=2;
            }
        }

        vector<int> posIdx;
        for (int i = 0; i < n; i++) {
            if (nums[i] ==1) {
                posIdx.push_back(i);
            }
        }

        int steps2=INT_MAX;
        if (posIdx.size() % 2 == 0) {
            isPossible = true;
            steps2=0;
            int i=0;
            while(i<posIdx.size()){
                steps2+= (posIdx[i+1]-posIdx[i]);
                i+=2;
            }
        }

        int totalSteps=min(steps1,steps2);
        if(isPossible){
            return totalSteps<=k;
        }

        return false;
    }
};
