

class Solution {
public:
    int minimumCost(vector<int>& nums) {
        int n=nums.size();
        int totalMinSum=nums[0];

        int secondMin=INT_MAX;
        int thirdMin=INT_MAX;

        for(int i=1;i<n;i++){
            int curElem=nums[i];

            if(curElem<secondMin){
                thirdMin=secondMin;
                secondMin=curElem;
            }
            else if(curElem<thirdMin){
                thirdMin=curElem;
            }
        }

        return (totalMinSum+secondMin+thirdMin);
    }
};
