// most optimal approach:
class Solution {
private:
    int euclidDistance(int x, int y) {
        int dist = x * x + y * y;
        return dist;
    }

    string changeDirection(string& curDir, int val) {

        if (curDir == "+y") {
            return val==-1 ? "+x" : "-x";
        } else if (curDir == "-y") {
            return val==-1 ? "-x" : "+x";
        } else if (curDir == "+x") {
            return val==-1 ? "-y" : "+y";
        } else {
            return val==-1 ? "+y" : "-y";
        }

        return "#";
    }

    auto getIncrement(string &curDir){
        pair<int,int> inc;

        if (curDir == "+y") {
            inc={0,1};
        } else if (curDir == "-y") {
            inc={0,-1};
        } else if (curDir == "+x") {
            inc={1,0};
        } else {
            inc={-1,0};
        }

        return inc;
    }
public:
    int robotSim(vector<int>& commands, vector<vector<int>>& obstacles) {
        unordered_set<string> st;

        for(auto &it:obstacles){
            int x=it[0];
            int y=it[1];

            string key=to_string(x)+"_"+to_string(y);
            st.insert(key);
        }
        int maxDist = 0;
        string dir = "+y";
        int i=0,j=0;
        for (int c : commands) {
            if(c<0){
                dir=changeDirection(dir,c);
            }
            else{
                int steps=1;
                auto increment=getIncrement(dir);
                while(steps<=c){

                    int nxtI=i+increment.first;
                    int nxtJ=j+increment.second;

                    string key=to_string(nxtI)+"_"+to_string(nxtJ);
                    if(st.count(key)){
                        break;
                    }
                    i=nxtI;
                    j=nxtJ;
                    steps++;
                    maxDist=max(maxDist,euclidDistance(nxtI,nxtJ));
                }
            }
        }

        return maxDist;
    }
};


// a better approach:
class Solution {
private:
    int euclidDistance(int x, int y) {
        int dist = x * x + y * y;
        return dist;
    }

    string changeDirection(string& curDir, int val) {

        if (curDir == "+y") {
            return val==-1 ? "+x" : "-x";
        } else if (curDir == "-y") {
            return val==-1 ? "-x" : "+x";
        } else if (curDir == "+x") {
            return val==-1 ? "-y" : "+y";
        } else {
            return val==-1 ? "+y" : "-y";
        }

        return "#";
    }

    auto getIncrement(string &curDir){
        pair<int,int> inc;

        if (curDir == "+y") {
            inc={0,1};
        } else if (curDir == "-y") {
            inc={0,-1};
        } else if (curDir == "+x") {
            inc={1,0};
        } else {
            inc={-1,0};
        }

        return inc;
    }
public:
    int robotSim(vector<int>& commands, vector<vector<int>>& obstacles) {
        unordered_map<int,unordered_map<int,bool>> mp;
        for (auto& it : obstacles) {
            mp[it[0]][it[1]]=true;
        }

        int maxDist = 0;
        string dir = "+y";
        int i=0,j=0;
        for (int c : commands) {
            if(c<0){
                dir=changeDirection(dir,c);
            }
            else{
                int steps=1;
                auto increment=getIncrement(dir);
                while(steps<=c){

                    int nxtI=i+increment.first;
                    int nxtJ=j+increment.second;

                    if(mp[nxtI][nxtJ]){
                        break;
                    }
                    i=nxtI;
                    j=nxtJ;
                    steps++;
                    maxDist=max(maxDist,euclidDistance(nxtI,nxtJ));
                }
            }
        }

        return maxDist;
    }
};

// A LITTLE BETTER APPROACH THAN THE brute force approach
// TIME : O(C*LOG(OBS))
// SPACE : O(OBS)
class Solution {
private:
    int euclidDistance(int x, int y) {
        int dist = x * x + y * y;
        return dist;
    }

    string changeDirection(string& curDir, int val) {

        if (curDir == "+y") {
            return val==-1 ? "+x" : "-x";
        } else if (curDir == "-y") {
            return val==-1 ? "-x" : "+x";
        } else if (curDir == "+x") {
            return val==-1 ? "-y" : "+y";
        } else {
            return val==-1 ? "+y" : "-y";
        }

        return "#";
    }

    auto getIncrement(string &curDir){
        pair<int,int> inc;

        if (curDir == "+y") {
            inc={0,1};
        } else if (curDir == "-y") {
            inc={0,-1};
        } else if (curDir == "+x") {
            inc={1,0};
        } else {
            inc={-1,0};
        }

        return inc;
    }
public:
    int robotSim(vector<int>& commands, vector<vector<int>>& obstacles) {
        set<pair<int, int>> obs;
        for (auto& it : obstacles) {
            obs.insert({it[0], it[1]});
        }

        int maxDist = 0;
        string dir = "+y";
        int i=0,j=0;
        for (int c : commands) {
            if(c<0){
                dir=changeDirection(dir,c);
            }
            else{
                int steps=1;
                auto increment=getIncrement(dir);
                while(steps<=c){

                    int nxtI=i+increment.first;
                    int nxtJ=j+increment.second;

                    if(obs.count({nxtI,nxtJ})){
                        break;
                    }
                    i=nxtI;
                    j=nxtJ;
                    steps++;
                    maxDist=max(maxDist,euclidDistance(nxtI,nxtJ));
                }
            }
        }

        return maxDist;
    }
};
