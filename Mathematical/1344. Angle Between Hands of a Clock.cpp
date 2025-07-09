class Solution {
public:
    double angleClock(int hour, int minutes) {
        // 60 min =360 deg
        double minuteAngle=6.0*(double)minutes;
        double hourAngle=30.0*(hour%12) + 0.5*(double)(minutes);

        double diff=abs(hourAngle-minuteAngle);

        return min(diff,360.0-diff);
    }
};
