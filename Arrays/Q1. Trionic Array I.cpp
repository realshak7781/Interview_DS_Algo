class Solution {
public:
    bool isTrionic(vector<int>& nums) {
        int n=nums.size();

        for(int p=1;p<=(n-3);p++){
            for(int q=p+1;q<n-1;q++){
                // nums[0...p] is strictly increasing,
                bool contnue=true;
                for(int i=1;i<=p;i++){
                    if(nums[i]<=nums[i-1]){
                        contnue=false;
                        break;
                    }
                }

                if(!contnue) continue;
                
                // nums[p...q] is strictly decreasing,
                 for(int i=p+1;i<=q;i++){
                    if(nums[i]>=nums[i-1]){
                        contnue=false;
                        break;
                    }
                }
                if(!contnue) continue;
               // nums[q...n − 1] is strictly increasing.

                  for(int i=q+1;i<n;i++){
                    if(nums[i]<=nums[i-1]){
                        contnue=false;
                        break;
                    }
                }
                if(!contnue) continue;

                return true;
            }
        }

        return false;
    }
};
