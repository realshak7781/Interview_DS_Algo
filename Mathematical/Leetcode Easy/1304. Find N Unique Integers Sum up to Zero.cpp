class Solution {
public:
    vector<int> sumZero(int n) {
        // Take the first n-1 nos as positive counting from 1 and then last no as -neg of the sum of all pos
        vector<int> res;
        int posCount=n-1;

        if(posCount==0){
            return {0};
        }

        for(int i=1;i<=posCount;i++){
            res.push_back(i);
        }

     
        int posSum=(posCount*(posCount+1))/2;

        int negVal=-1*posSum;

        res.push_back(negVal);

        return res;
    }
};
