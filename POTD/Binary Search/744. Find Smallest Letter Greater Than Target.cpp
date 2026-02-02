
class Solution {
public:
    char nextGreatestLetter(vector<char>& letters, char target) {
        int n=letters.size();

        int low=0,high=n-1;
        int idx=0;
        while(low<=high){
            int mid=low+(high-low)/2;

            char cur=letters[mid];

            if(cur>target){
                idx=mid;
                high=mid-1;
            }
            else{
                low=mid+1;
            }
        }


        return letters[idx];
    }
};
