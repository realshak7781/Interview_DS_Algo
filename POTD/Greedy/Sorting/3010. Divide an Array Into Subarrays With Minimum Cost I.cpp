// brute force approach
// time : o(n*n)

class Solution {
public:
    int minimumCost(vector<int>& nums) {
        // lets try the brute force approach for this problem

        int n=nums.size();
        int totalMinSum=INT_MAX;

        // i,j marrks the ending of the subarrays
        for(int i=0;i<=(n-3);i++){
            for(int j=i+1;j<(n-1);j++){

                totalMinSum=min(totalMinSum,nums[0]+nums[i+1]+nums[j+1]);
            }
        }

        return totalMinSum;
    }
};

// Using obervation 
// time : O(n)
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
