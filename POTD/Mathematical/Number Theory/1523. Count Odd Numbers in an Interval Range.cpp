class Solution {
private:
int approach1(int low,int high){
    if(low%2==0) low++;
    if(high%2==0) high--;

    return (high-low)/2 +1;
}
int approach2(int low,int high){

    return (high+1)/2 - low/2;
}
public:
    int countOdds(int low, int high) {
        return approach2(low,high);
    }
};
