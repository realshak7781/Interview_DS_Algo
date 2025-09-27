class Solution {
private:
double getArea(auto &p1,auto &p2,auto &p3){
    double x1=p1[0];
    double x2=p2[0];
    double x3=p3[0];
    double y1=p1[1];
    double y2=p2[1];
    double y3=p3[1];

    double a=sqrt(pow(x2-x1,2)+pow(y2-y1,2));
    double b=sqrt(pow(x3-x1,2)+pow(y3-y1,2));
    double c=sqrt(pow(x3-x2,2)+pow(y3-y2,2));

    double s=(a+b+c)*0.5;

    double area=s*(s-a)*(s-b)*(s-c);

    if(area<0.0) return 0.0;

    return sqrt(area);
}
public:
    double largestTriangleArea(vector<vector<int>>& points) {
        int n=points.size();
        double maxArea=0.0;

        for(int i=0;i<n;i++){
            for(int j=i+1;j<n;j++){
                for(int k=j+1;k<n;k++){
                    auto p1=points[i];
                    auto p2=points[j];
                    auto p3=points[k];

                    double area=getArea(p1,p2,p3);
                    maxArea=max(area,maxArea);
                }
            }
        }

        return maxArea;
    }
};
