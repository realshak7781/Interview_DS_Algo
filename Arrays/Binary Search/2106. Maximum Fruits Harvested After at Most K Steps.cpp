class Solution {
public:
    int maxTotalFruits(vector<vector<int>>& fruits, int startPos, int k) {
        // story points:

        // 1. the optimal path is to explore all left and then all right and then go left turn right and then vice versa

        // all left and all right are easy
        // left , turn right or vice versa complex:

        // suppose if we go x steps left , then from that pos we can go k-x steps right
        // do this for the movement : turn right and the  turn left

        int totalPos=fruits.size();
        vector<int> prefSum(totalPos,0);

        prefSum[0]=fruits[0][1];
        vector<int>positions;
        positions.push_back(fruits[0][0]);
        for(int i=1;i<totalPos;i++){
            int pos=fruits[i][0];
            int f=fruits[i][1];

            prefSum[i]=prefSum[i-1]+f;
            positions.push_back(fruits[i][0]);
        }

        // to find the total fruits in the range

        // first two cases take extreme left and extreme right case
        int res=0;

        for(int d=0;d<=k/2;d++){
            // case 1: go left and turn right
            int remain=k-2*d;
            int i=startPos-d;
            int j=startPos+remain;
            
            int left=lower_bound(begin(positions),end(positions),i)-positions.begin();
            int right=upper_bound(begin(positions),end(positions),j)-positions.begin()-1;

            if(left<=right){
                int fr=prefSum[right]-(left>0?prefSum[left-1]:0);
                res=max(res,fr);
            }
            // case 2 : go rigth and turn left

            j=startPos+d;
            i=startPos-remain;

            left=lower_bound(begin(positions),end(positions),i)-positions.begin();
            right=upper_bound(begin(positions),end(positions),j)-positions.begin()-1;

            if(left<=right){
                int fr=prefSum[right]-(left>0?prefSum[left-1]:0);
                res=max(res,fr);
            }
        }

        return res;
    }
};
