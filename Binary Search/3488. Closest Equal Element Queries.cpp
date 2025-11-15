
class Solution {
private:
int size;
vector<int> bruteForce(vector<int>& nums, vector<int>& queries){
    vector<int> res(queries.size(),-1);

    for(int qi=0;qi<queries.size();qi++){
        int q=queries[qi];
        int elem=nums[q];

        // traverse in both directions in circular fashion
        int minDist=INT_MAX;
        int dist=1;

        int nextIdx=(q+1)%size;
        while(nextIdx!=q){
            if(nums[nextIdx]==elem){
                minDist=min(dist,minDist);
                break;
            }
            dist++;
            nextIdx=(nextIdx+1)%size;
        }

        // now go back circular way
        int prevIdx=(q-1+size)%size;
        dist=1;

        while(prevIdx!=q){
            if(nums[prevIdx]==elem){
                minDist=min(minDist,dist);
                break;
            }
            dist++;
            prevIdx=(prevIdx-1+size)%size;
        }

        if(minDist!=INT_MAX){
            res[qi]=minDist;
        }
    }

    return res;
}

int binarySearch(int low,int high,vector<int>&indexes,int q){
    while(low<=high){
        int mid=low+(high-low)/2;

        if(indexes[mid]>q){
            high=mid-1;
        }
        else if(indexes[mid]<q){
            low=mid+1;
        }
        else{
            return mid;
        }
    }

    return -1;
}

vector<int> optimal(vector<int>&nums,vector<int>&queries){
   int n=nums.size();
    vector<int> res(queries.size(),-1);

    unordered_map<int,vector<int>> mp;
    for(int i=0;i<n;i++){
        mp[nums[i]].push_back(i);
    }

    for(int qi=0;qi<queries.size();qi++){
        int q=queries[qi];
        int elem=nums[q];

        vector<int> &indexes=mp[elem];
        int m=indexes.size();
        int idx=binarySearch(0,m-1,indexes,q);

        int dist=INT_MAX;
        int left=(idx-1+m)%m;
        int right=(idx+1)%m;

        if(!(m==1)){
            dist=min(abs(q-indexes[left]),abs(q-indexes[right]));
            // below both are edge acses
            dist=min(dist,n-q+indexes[right]);
            dist=min(dist,abs(q+n-indexes[left]));
            res[qi]=dist;
        }
      
    }

    return res;
}
public:
    vector<int> solveQueries(vector<int>& nums, vector<int>& queries) {
       return optimal(nums,queries);
    }
};
