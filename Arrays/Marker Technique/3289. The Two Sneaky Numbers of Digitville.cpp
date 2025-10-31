// ook for problems where the input array (of size $n$) contains integers that fall within a specific, bounded range directly related to its size, such as $[0, n-1]$ or $[1, n]$. 
// The task will almost always involve finding missing numbers, duplicates, or a mismatched pair. When you see this range constraint, especially if the problem asks for an $O(1)$ constant space and $O(n)$ linear time solution, 
//   it's a strong signal to use the array's indices as a "hash map" or "checklist." This can be done by either negating values at corresponding indices to "mark" them as seen or by swapping elements to their correct positions (Cyclic Sort).



class Solution {
public:
    vector<int> getSneakyNumbers(vector<int>& nums) {
        int n=nums.size();

        vector<int> res;
        for(int i=0;i<n;i++){
            int pos=abs(nums[i]);

            if(pos==n) pos=0;
            
            if(nums[pos]>0){
                nums[pos]=-1*nums[pos];
            }
            else if(nums[pos]==0){
                nums[pos]=-n;
            }
            else if(nums[pos]<0){
                res.push_back(pos);
            }
        }

        return res;
    }
};
