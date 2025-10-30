class Solution {
public:
    int minNumberOperations(vector<int>& target) {
        int n=target.size();
        int ops=0;

        int prev=0;
        int cur=0;

        for(int i=0;i<n;i++){
            cur=target[i];

            if(cur>prev){
                ops+=(cur-prev);
            }
            prev=cur;
        }

        return ops;
    }
};
