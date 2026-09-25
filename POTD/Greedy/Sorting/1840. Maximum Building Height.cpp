class Solution {
public:
    int maxBuilding(int n, vector<vector<int>>& restrictions) {

        restrictions.insert(restrictions.begin(), {1, 0});
        restrictions.push_back({n, n - 1});

        int totalRestrictions = restrictions.size();
        sort(begin(restrictions), end(restrictions));

        // adjust the heights
        // usign a twp pass technique
        for (int i = 1; i < totalRestrictions; i++) {
            int prevId = restrictions[i - 1][0];
            int prevH = restrictions[i - 1][1];
            int curId = restrictions[i][0];
            int curRestriction = restrictions[i][1];

            int bestH = prevH + (curId - prevId);
            restrictions[i][1] = min(curRestriction, bestH);
        }

        // second pass
        for(int i=totalRestrictions-2;i>=0;i--){
            int nextId=restrictions[i+1][0];
            int nextH=restrictions[i+1][1];
            int curId=restrictions[i][0];
            int curRestriction=restrictions[i][1];

            int bestH=nextH+(nextId-curId);
            restrictions[i][1]=min(curRestriction,bestH);
        }

        int resH = 0;

        for (int i = 1; i < totalRestrictions; i++) {
            int prevId = restrictions[i - 1][0];
            int prevH = restrictions[i - 1][1];
            int curId = restrictions[i][0];
            int curH = restrictions[i][1];
            resH=max(resH,curH);
            int maxH=max(prevH,curH);
            int minH=min(curH,prevH);
            int peak=maxH + (curId- (prevId+maxH-minH))/2;
            resH=max(resH,peak);
        }

        return resH;
    }
};
