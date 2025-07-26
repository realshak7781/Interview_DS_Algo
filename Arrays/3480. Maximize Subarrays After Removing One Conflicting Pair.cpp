using ll=long long;
class Solution {
public:
    long long maxSubarrays(int n, vector<vector<int>>& conflictingPairs) {
        ll valid=0;

        vector<vector<int>> conflictingPoints(n+1);
        // conflictingPoints[i]= list of points conflicting with i

        for(auto &p:conflictingPairs){
            // O(c)
            int a=min(p[0],p[1]);
            int b=max(p[0],p[1]);
            conflictingPoints[b].push_back(a);
            // the point b is in conflict with a ---> {2,5}
        }

        ll maxConflict=0;
        ll secondMaxConflict=0;

        vector<ll> extra(n+1,0);

        for(int end=1;end<=n;end++){
            // O(n)+O(p)
// /we will count the subarrays ending at end and extra subarrays if the maxConflict piint is removed
            for(auto &u:conflictingPoints[end]){
                if(u>maxConflict){
                    secondMaxConflict=maxConflict;
                    maxConflict=u;
                }
                else if(u>secondMaxConflict){
                    secondMaxConflict=u;
                }
            }

            valid+=(end-maxConflict);
            extra[maxConflict]+=(maxConflict-secondMaxConflict);
        }

        valid+=*max_element(begin(extra),end(extra));

        return valid;
    }
};
