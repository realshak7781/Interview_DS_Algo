class Solution {
public:
    int findClosest(int x, int y, int z) {
        // since speed is same for travel for both p1 and p2
        // time is directly proportional to distance of p1 and p2 from p3

        int d1=abs(x-z);
        int d2=abs(y-z);

        if(d1<d2){
            return 1;
        }
        else if(d2<d1){
            return 2;
        }
        else{
            return 0;
        }

        return -1;
    }
};
