

// TIME : O(NLOGN) + O(N*N)
// SPACE : O(N)
// BRUTE FORCE IMPLEMENTATION
struct Node{
    int position;
    char direction;
    int original_idx;
};

class Solution {
public:
    vector<int> survivedRobotsHealths(vector<int>& positions, vector<int>& healths, string directions) {
        vector<Node> vec;

        for(int i=0;i<positions.size();i++){
            vec.emplace_back(positions[i],directions[i],i);
        }

        // sort the array based on the position
        sort(vec.begin(),vec.end(),[](const Node&a,const Node&b){
            return a.position < b.position;
        });

        // now collision only occurs if twp bodies are mpving in (R,L) fashion
        int totalRobots=vec.size();
        for(int i=0;i<totalRobots;i++){
            if(vec[i].direction=='R') continue;

            // found a left side going robot
            // now it wants  a right side going robot
            int j=i-1;

            while(j>=0){

                if(healths[vec[j].original_idx]==-1){
                    // ignore 
                    j--;
                    continue;
                }
                if(vec[j].direction=='L'){
                    break;
                }
                int cur_health=healths[vec[i].original_idx];
                int prev_health=healths[vec[j].original_idx];
                // now current j can be big R
                if(prev_health>cur_health){
                    if(healths[vec[j].original_idx]>0){
                        healths[vec[j].original_idx]--;
                    }
                    healths[vec[i].original_idx]=-1;
                    break;
                }
                // current j can be small R
                else if(prev_health<cur_health){
                     if(healths[vec[i].original_idx]>0){
                        healths[vec[i].original_idx]--;
                    }
                    healths[vec[j].original_idx]=-1;
                    j--;
                }// current j can be equal R
                else{
                    healths[vec[i].original_idx]=-1;
                    healths[vec[j].original_idx]=-1;
                    break;
                }
            }
        }


        sort(vec.begin(),vec.end(),[](const Node&a,const Node&b){
            return a.original_idx < b.original_idx;
        });

        vector<int> res;

        for(int i=0;i<totalRobots;i++){
            if(healths[vec[i].original_idx]>=0){
                res.push_back(healths[vec[i].original_idx]);
            }
        }

        return res;
    }
};
