// Time : O(mlogm) + O(m)
// space : O(1)
class Solution {
public:
    int minimumBoxes(vector<int>& apple, vector<int>& capacity) {
        int n=capacity.size();
        int totalApples=accumulate(apple.begin(),apple.end(),0);
        sort(begin(capacity),end(capacity));

        int res=0;
        for(int i=n-1;i>=0;i--){
            if(totalApples<=0) return res;
            totalApples-=capacity[i];
            res++;
        }

        return res;
    }
};
