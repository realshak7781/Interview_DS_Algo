// Using BINARY SEARCH ON ANSWERS
// TIME : O(NLOGN) + oO(LOG(109))
// SPACE: O(N)

struct Node{
    int diff;
    int actual;
    int min;
};
class Solution {
private:
bool check(int energy,vector<Node>&res){
    for (auto &node : res) {
        if (energy < node.min)
            return false;

        energy -= node.actual;
    }

    return energy>=0;
}
public:
    int minimumEffort(vector<vector<int>>& tasks) {
        vector<Node> res;
        int maxi=-1;
        for(auto &vec:tasks){
            res.push_back({vec[1]-vec[0],vec[0],vec[1]});
            maxi=max(maxi,vec[1]);
        }


        sort(begin(res),end(res),[&](Node &a,Node&b){
            if(a.diff!=b.diff){
                // largest diff first
                return a.diff>b.diff;
            }
            
            if(a.min!=b.min){
                // largest min enerygy first
                return a.min>b.min;
            }
            return a.actual < b.actual; 
        });


        // use binary search on ans

        int low=maxi;
        int high=INT_MAX;
        int reqEnergy=-1;
        while(low<=high){
            int mid=low+(high-low)/2;

            if(check(mid,res)){
                reqEnergy=mid;
                high=mid-1;
            }
            else{
                low=mid+1;
            }
        }

        return reqEnergy;
    }
};
