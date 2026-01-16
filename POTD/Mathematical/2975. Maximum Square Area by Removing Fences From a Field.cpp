// Time :O(nlong + mlogm + n*n + m*m)
// space : O(max(n,m))

class Solution {
private:
const int mod=1e9+7;
public:
    int maximizeSquareArea(int m, int n, vector<int>& hFences, vector<int>& vFences) {
        hFences.insert(hFences.begin(),1);
        hFences.insert(hFences.end(), m);
        vFences.insert(vFences.begin(), 1);
        vFences.insert(vFences.end(), n);

        sort(begin(hFences),end(hFences));
        sort(begin(vFences),end(vFences));
        unordered_set<int> seen;

        int res=-1;
        for(int i=0;i<hFences.size();i++){
            for(int j=i+1;j<hFences.size();j++){
                int side=hFences[j]-hFences[i];
                seen.insert(side);
            }
        }

         for(int i=0;i<vFences.size();i++){
            for(int j=i+1;j<vFences.size();j++){
                int side=vFences[j]-vFences[i];
                if(seen.count(side)){
                    res=max(res,side);
                }
            }
        }

        long long area=-1;
        if(res!=-1)area=(1LL*res*res)%mod;
        return area;
    }
};
