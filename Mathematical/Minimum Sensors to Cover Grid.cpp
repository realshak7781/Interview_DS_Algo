class Solution {
public:
    int minSensors(int n, int m, int k) {
        int region=2*k+1;
        int rowSensors=ceil((double)n/region);
        int colSensors=ceil((double)m/region);

        return rowSensors*colSensors;
    }
};
