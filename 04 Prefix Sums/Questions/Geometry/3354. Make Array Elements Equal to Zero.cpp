
// O(N) solutoion using prefix and suffix sum
class Solution {
public:
    int countValidSelections(vector<int>& nums) {
        int n=nums.size();
        vector<int> pre(n,0);
        vector<int> suff(n,0);

        pre[0]=nums[0];
        suff[n-1]=nums[n-1];
        for(int i=1;i<n;i++){
            pre[i]=nums[i]+pre[i-1];
        }

        for(int i=n-2;i>=0;i--){
            suff[i]=suff[i+1]+nums[i];
        }

        int valid=0;

        for(int i=0;i<n;i++){
            if(nums[i]>0) continue;

            int leftSum=(i>0 ? pre[i-1]:0);
            int rightSum=(i<n-1 ? suff[i+1]:0);

            if(leftSum==rightSum){
                valid+=2;
            }
            else if(abs(leftSum-rightSum)==1){
                valid+=1;
            }
        }

        return valid;
    }
};

// Brute force : O(N^2) solution
class Solution {
private:
int simulate(int curIdx,vector<int> nums,bool direction){
    int n=nums.size();


    while(true){
        if(curIdx<0 || curIdx>=n) break;

        if(nums[curIdx]>0){
            nums[curIdx]--;
            direction=direction^1;
        }

        if(direction){
            curIdx+=1;
        }
        else{
            curIdx-=1;
        }
    }

    // check for all zeeroes arr
    for(int i=0;i<n;i++){
        if(nums[i]>0) return 0;
    }
    return 1;
}
public:
    int countValidSelections(vector<int>& nums) {
        int n=nums.size();

        int valid=0;
        for(int i=0;i<n;i++){
            if(nums[i]!=0) continue;

            valid+=simulate(i+1,nums,true);
            valid+=simulate(i-1,nums,false);

            // true :right : i+1;
            // false: left : i-1
        }

        return valid;
    }
};
