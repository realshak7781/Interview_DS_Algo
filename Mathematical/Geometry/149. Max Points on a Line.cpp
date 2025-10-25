class Solution {
private:
int gcd(int a,int b){
    if(b==0) return a;

    return gcd(b,a%b);
}
string getSlope(int x,int y){

    if(x==0 && y==0){
        return "duplicate";
    }

    if(x==0){
        return "horizontal";
    }

    if(y==0){
        return "vertical";
    }
    int g=gcd(abs(x),abs(y));
    x/=g;
    y/=g;

    // normalization of signs is a must  : beacuse {(1,1), (-1,-1)} are same  and {(1,-1) , (-1,1) } are same
    if(x<0){
        x=-x;
        y=-y;
    }

    return to_string(x) + "_" + to_string(y);
}
public:
    int maxPoints(vector<vector<int>>& points) {
        int n=points.size();
        if(points.size()<=2) return n;

        int maxCount=0;
        for(int i=0;i<n;i++){
            for(int j=i+1;j<n;j++){
                int count=2;
                int x1 = points[i][0];
                int y1 = points[i][1];
                int x2 = points[j][0];
                int y2 = points[j][1];

                int y=y2-y1;
                int x=x2-x1;

                // to avoid precision errors : we will convert the 
                string slope=getSlope(x,y);
                for(int k=j+1;k<n;k++){
                    int x3=points[k][0];
                    int y3=points[k][1];

                    int x=x3-x1;
                    int y=y3-y1;

                    string newSlope=getSlope(x,y);

                    if(slope==newSlope)count++;
                }

                maxCount=max(maxCount,count);
            }
        }

        return maxCount;
    }
};
