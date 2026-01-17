// Using mathematics and Geometry
// Time : O(n*2)
// space : O(1)
using ll = long long;
class Solution {
public:
    long long largestSquareArea(vector<vector<int>>& bottomLeft,
                                vector<vector<int>>& topRight) {
        int totalRect = bottomLeft.size();
        ll resSide = 0;

        for (int i = 0; i < totalRect; i++) {
            int ax1, ay1, ax2, ay2;
            ax1 = bottomLeft[i][0];
            ay1 = bottomLeft[i][1];
            ax2 = topRight[i][0];
            ay2 = topRight[i][1];

            for (int j = i + 1; j < totalRect; j++) {
                int bx1, by1, bx2, by2;
                bx1 = bottomLeft[j][0];
                by1 = bottomLeft[j][1];
                bx2 = topRight[j][0];
                by2 = topRight[j][1];

                // check if they overlap or not
                if(ax2 < bx1 ||  bx2<ax1  || ay2<by1 || by2<ay1) continue; /* doesnt intersect*/

                // it intersects
                // find the coordinates of intersecting regions
                int xLeft=max(ax1,bx1);
                int xRight=min(ax2,bx2);
                int yBottom=max(ay1,by1);
                int yTop=min(ay2,by2);

                ll sideLen=min(abs(yTop-yBottom),abs(xRight-xLeft));
                resSide=max(resSide,sideLen);
            }
        }

        ll sqArea=resSide*resSide;

        return sqArea;
    }
};
