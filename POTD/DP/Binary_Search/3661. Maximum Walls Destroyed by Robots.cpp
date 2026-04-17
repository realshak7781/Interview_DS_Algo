

// TIME : O(N*WALLS_SIZE)
// SPACE : O(N)
// APPROACH 2:
// USING DIR VARIABLE TO HANDLE THE STATE FOR BROKEN WALLS ARRAY
struct Node{
    int l;
    int r;
    Node(){
        l=0;
        r=0;
    }
    Node(int leftR,int rightR){
        l=leftR;
        r=rightR;
    }
};
class Solution {
private:
vector<pair<Node,Node>> robotRanges;
int totalRobots;

unordered_map<int,unordered_map<int,int>> dp;
int countWallsDestroyed(int l,int r,vector<int>&walls){
    int totalDestroyed=0;

    for(int i=0;i<walls.size();i++){
        if(walls[i]>=l && walls[i]<=r){
            totalDestroyed++;
        }
    }
    return totalDestroyed;
}

int solve(int idx,vector<int>& walls,int dir){
    if(idx>=totalRobots){
        return 0;
    }

    if(dp[idx].count(dir)) return dp[idx][dir];
    int totalDestroyed=0;

    Node leftNode=robotRanges[idx].first;
    // current robot left range
    Node rightNode=robotRanges[idx].second;
    // current robot right range

    int leftStart=leftNode.l;
    // i want to shoot left but the previous robot shot right
    if(idx>0 && dir==1){
        leftStart=max(leftStart,robotRanges[idx-1].second.r+1);
    }
    totalDestroyed=countWallsDestroyed(leftStart,leftNode.r,walls) + solve(idx+1,walls,0);

    // i want to shoot right
    int destroyedRight=countWallsDestroyed(rightNode.l,rightNode.r,walls);

    totalDestroyed=max(totalDestroyed,destroyedRight+solve(idx+1,walls,1));

    return dp[idx][dir]=totalDestroyed;
}
public:
    int maxWalls(vector<int>& robots, vector<int>& distance, vector<int>& walls) {
        vector<pair<int,int>> robDistance;
        // {robot_dist,range}
        for(int i=0;i<robots.size();i++){
            robDistance.push_back({robots[i],distance[i]});
        }

        sort(robDistance.begin(),robDistance.end(),[](const pair<int,int>&a,const pair<int,int>&b){
            return a.first < b.first;
            // sorting the robDistance array based on the robot coordinates
        });

        totalRobots=robDistance.size();
        robotRanges.resize(totalRobots);
        for(int i=0;i<totalRobots;i++){
            int cord=robDistance[i].first;
            int r=robDistance[i].second;
            // process the left range first
            Node leftNode;
            if(i==0){
                leftNode=Node(cord-r,cord);
            }
            else{
                int prevCord=robDistance[i-1].first;
                leftNode=Node(max(cord-r,prevCord+1),cord);
            }

            // process the right robot
            Node rightNode;
            if(i==(totalRobots-1)){
                rightNode=Node(cord,cord+r);
            }
            else{
                int nextCord=robDistance[i+1].first;
                rightNode=Node(cord,min(cord+r,nextCord-1));
            }
            robotRanges[i] = {leftNode, rightNode};
        }

        sort(walls.begin(),walls.end());

        return solve(0,walls,0);
    }
};


// Using Recursion and Backtracking
// Time : Exponential
// space : O(n)

struct Node{
    int l;
    int r;
    Node(){
        l=0;
        r=0;
    }
    Node(int leftR,int rightR){
        l=leftR;
        r=rightR;
    }
};
class Solution {
private:
vector<pair<Node,Node>> robotRanges;
int totalRobots;
vector<bool> brokenWalls;

// trying to memoize it
unordered_map<int,int> dp;
int solve(int idx,vector<int>& walls){
    if(idx>=totalRobots){
        return 0;
    }

    if(dp.count(idx)) return dp[idx];
    int totalDestroyed=0;
    // at each idx i have two options
    Node leftR=robotRanges[idx].first;
    // fire the bullet to the left destroy walls in the range
    for(int i=0;i<walls.size();i++){
        if(!brokenWalls[i] && walls[i]>=leftR.l && walls[i]<=leftR.r){
            brokenWalls[i]=true;
            totalDestroyed+=1;
        }
    }

    totalDestroyed=totalDestroyed+solve(idx+1,walls);

    // resetting   the broken walls
     for(int i=0;i<walls.size();i++){
        if(brokenWalls[i] && walls[i]>=leftR.l && walls[i]<=leftR.r){
            brokenWalls[i]=false;
        }
    }

    // fire the bullet to the right and destroy walls in the range
    Node rightR=robotRanges[idx].second;
    int destroyedUsingRight=0;

    for(int i=0;i<walls.size();i++){
        if(!brokenWalls[i] && walls[i]>=rightR.l && walls[i]<=rightR.r){
            brokenWalls[i]=true;
            destroyedUsingRight+=1;
        }
    }

    totalDestroyed=max(totalDestroyed,destroyedUsingRight+solve(idx+1,walls));

    for(int i=0;i<walls.size();i++){
        if(brokenWalls[i] && walls[i]>=rightR.l && walls[i]<=rightR.r){
            brokenWalls[i]=false;
        }
    }

    return dp[idx]=totalDestroyed;
}
public:
    int maxWalls(vector<int>& robots, vector<int>& distance, vector<int>& walls) {
        vector<pair<int,int>> robDistance;
        // {robot_dist,range}
        for(int i=0;i<robots.size();i++){
            robDistance.push_back({robots[i],distance[i]});
        }

        sort(robDistance.begin(),robDistance.end(),[](const pair<int,int>&a,const pair<int,int>&b){
            return a.first < b.first;
            // sorting the robDistance array based on the robot coordinates
        });

        totalRobots=robDistance.size();
        robotRanges.resize(totalRobots);
        for(int i=0;i<totalRobots;i++){
            int cord=robDistance[i].first;
            int r=robDistance[i].second;
            // process the left range first
            Node leftNode;
            if(i==0){
                leftNode=Node(cord-r,cord);
            }
            else{
                int prevCord=robDistance[i-1].first;
                leftNode=Node(max(cord-r,prevCord+1),cord);
            }

            // process the right robot
            Node rightNode;
            if(i==(totalRobots-1)){
                rightNode=Node(cord,cord+r);
            }
            else{
                int nextCord=robDistance[i+1].first;
                rightNode=Node(cord,min(cord+r,nextCord-1));
            }
            robotRanges[i] = {leftNode, rightNode};
        }

        sort(walls.begin(),walls.end());
        brokenWalls.resize(walls.size(),false);

        return solve(0,walls);
    }
};
