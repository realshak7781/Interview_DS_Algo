class Solution {
public:
    vector<int> avoidFlood(vector<int>& rains) {
        int n=rains.size();
        unordered_map<int,int> lastRain;
        set<int> dryDays;

        vector<int> res(n,1);
        for(int i=0;i<n;i++){
            int lake=rains[i];

            if(lake==0){
                dryDays.insert(i);
                continue;
            }

            if(!lastRain.count(lake)){
                lastRain[lake]=i;
                res[i]=-1;
            }
            else{
                int lastDay=lastRain[lake];
                lastRain[lake]=i;

                auto it=dryDays.lower_bound(lastDay);

                if(it!=dryDays.end()){
                    int idx=*it;
                    res[idx]=lake;
                    dryDays.erase(it);
                    res[i]=-1;
                }
                else{
                    return {};
                }
            }
        }

        return res;
    }
};
