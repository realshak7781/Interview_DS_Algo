class Solution {
public:
    int twoCitySchedCost(vector<vector<int>>& costs) {
        int n=costs.size()/2;

        int mistakeCost=0;
        // by mistake i booked evryones A city ticket

        for(auto &c:costs){
            mistakeCost+=c[0];
        }


        // now i need to remove n persons A cost and add b cost in my mistake cost so the split for city a and city b is N:N

        // but this is equivalent to adding min(bcost-acost) to mistake cost

        vector<int> bPeople;
        for(auto &c:costs){
            bPeople.push_back(c[1]-c[0]);
        }

        sort(begin(bPeople),end(bPeople));

        for(int i=0;i<n;i++){
            mistakeCost+=bPeople[i];
        }

        return mistakeCost;
    }
};
