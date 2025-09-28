class Solution {
private:
bool isPossible(int a,int b,int c){
    if(a+b>c && a+c>b && b+c>a) return true;
    return false;
}
public:
    int largestPerimeter(vector<int>& nums) {
        int n=nums.size();

        sort(begin(nums),end(nums));

        int maxPeri=0;
        for(int i=n-1;i>=2;i--){
            int a=nums[i];
            int b=nums[i-1];
            int c=nums[i-2];
            int pm=a+b+c;
            if(isPossible(a,b,c)){
                maxPeri=max(maxPeri,pm);
            }
        }

        return maxPeri;
    }
};
