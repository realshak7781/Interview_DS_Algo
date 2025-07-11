class Solution {
public:
    vector<int> beautifulArray(int n) {
        vector<int> result={1};

        while(result.size()<n){
            vector<int> temp;

            // for odd subset
            //  for example for n=5:
            // odd subset :{1,5,3}
            // even subset : {2,4}  ----> combine both
            for(int &x:result){
                if(2*x-1<=n)temp.push_back(2*x-1);
            }

            // for even subset
            for(int &x:result){
                if(2*x<=n)temp.push_back(2*x);
            }

            result=temp;
        }

        return result;
    }
};
