class Solution {
public:
    int numOfUnplacedFruits(vector<int>& fruits, vector<int>& baskets) {
        int n=fruits.size();

        int count=0;
        for(int i=0;i<n;i++){
            int type=i;
            int quant=fruits[i];

            bool placed=false;
            for(int j=0;j<baskets.size();j++){
                if(baskets[j]!=-1 && baskets[j]>=quant){
                    placed=true;
                    baskets[j]=-1;
                    break;
                }
            }
            if(!placed) count++;
        }

        return count;
    }
};
