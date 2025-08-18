const double EPS=1e-6;
class Solution {
private:
bool solve(vector<double>&nums){
    int n=nums.size();
    if(nums.size()==1){
        return abs(nums[0]-24)<=EPS;
    }

    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            if(i==j)continue;

            vector<double> nextNums;
            for(int k=0;k<n;k++){
                if(k!=i && k!=j){
                    nextNums.push_back((double)nums[k]);
                }
            }
            double a=nums[i];
            double b=nums[j];
            vector<double> opVal={a+b,a-b,b-a,a*b};

            if(abs(b)>0.0){
                opVal.push_back(a/b);
            }

            if(abs(a)>0.0){
                opVal.push_back(b/a);
            }

            for(int i=0;i<opVal.size();i++){
                nextNums.push_back(opVal[i]);
                if(solve(nextNums)) return true;
                nextNums.pop_back();
            }
        }
    }

    return false;
}
public:
    bool judgePoint24(vector<int>& cards) {
        int n=cards.size();
        vector<double> nums;
        for(int i=0;i<n;i++){
            nums.push_back((double)(cards[i]));
        }

        return solve(nums);
    }
};
