// APPROACH 2:
// USING SEGMENT TREES
// TIME : O(QLOGQ)
// SPACE : O(20*1e4) +o(q)


class Solution {
private:
void updateQuery(int x,int upVal,int idx,int l,int r,vector<int>&segTree){
    if(l==r){
        segTree[idx]=upVal;
        return;
    }

    int mid=l+(r-l)/2;

    if(x<=mid){
        updateQuery(x,upVal,2*idx+1,l,mid,segTree);
    }
    else{
        updateQuery(x,upVal,2*idx+2,mid+1,r,segTree);
    }

    segTree[idx]=max(segTree[2*idx+1],segTree[2*idx+2]);
}

int querySegTree(int start,int end,int idx,int l,int r,vector<int>&segTree){
    if(l>end || r<start) return 0;

    if(l>=start && r<=end){
        return segTree[idx];
    }

    int mid=l+(r-l)/2;

    return max(
        querySegTree(start,end,2*idx+1,l,mid,segTree),
        querySegTree(start,end,2*idx+2,mid+1,r,segTree)
        );
}
public:
    vector<bool> getResults(vector<vector<int>>& queries) {
        set<int> obstacles;
        obstacles.insert(0);

        int size=5*1e4+1;
        vector<int> segTree(4*size,0);


        vector<bool> res;
        for(auto &q:queries){
            int qType=q[0];
            int x=q[1];
            if(qType==1){
                auto it=obstacles.upper_bound(x);
                int nxt=(it==obstacles.end()? -1:*it);
                int prv=*prev(it);

                updateQuery(x,x-prv,0,0,size-1,segTree);
                if(nxt!=-1){
                    updateQuery(nxt,nxt-x,0,0,size-1,segTree);
                } 

                obstacles.insert(x);
            }
            else{
                int sz=q[2];

                auto it=obstacles.upper_bound(x);
                int prv=*prev(it);

                int maxGap=querySegTree(0,prv,0,0,size-1,segTree);
                maxGap=max(maxGap,x-prv);

                if(maxGap>=sz){
                    res.push_back(true);
                }
                else{
                    res.push_back(false);
                }
            }
        }

        return res;
    }
};


// USING BRUTE FORCE APPROACH :
// TIME : O(QLOGQ + Q*Q)
// SPACE : O(Q)
class Solution {
private:
    set<int> obstacles;

public:
    vector<bool> getResults(vector<vector<int>>& queries) {
        vector<bool> res;

        for (auto& q : queries) {
            if (q[0] == 1) {
                obstacles.insert(q[1]);
            } else {
                int x = q[1];
                int sz = q[2];

                if (x >= sz) {

                    if(obstacles.empty()){
                        res.push_back(true);
                        continue;
                    }

                    int prev = 0;
                    int maxGap = 0;
                    for (int cur : obstacles) {
                        if (cur > x)
                            break;
                        int gap = cur - prev;
                        maxGap = max(maxGap, gap);
                        prev = cur;
                    }

                    maxGap=max(maxGap,x-prev);
                    // last gap between obtsacles and current object
                    if (maxGap >= sz) {
                        res.push_back(true);
                    }else{
                        res.push_back(false);
                    }
                }
                else{
                    res.push_back(false);
                }
            }
        }
        return res;
    }
};
