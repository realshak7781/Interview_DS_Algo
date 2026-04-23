// Optimal Approach:
class Robot {
private:
int totalVal;
int curVal;
int W,H;
bool moved;
auto getPair(int val,int W,int H){
    pair<pair<int,int>,string> res;

    if(val<W){
        // East
        res={{val,0},"East"};
    }
    else if(val>=W && val<=(W+H-2)){
        int c=val-(W-1);
        int r=W-1;

        res={{r,c},"North"};
    }
    else if(val>=(W+H-1) && val<(2*W+H-2)){
        int c=H-1;
        int r=W-1-(val-(W+H-2));

        res={{r,c},"West"};
    }
    else if(val>=(2*W+H-2)){
        int c=H-1 -(val-(2*W+H-3));
        int r=0;

        res={{r,c},"South"};
    }

    return res;
}
public:
    Robot(int width, int height) {
        curVal=0;
        totalVal=2*(width+height)-4;
        W=width;
        H=height;
        moved=false;
    }
    
    void step(int num) {
        moved=true;
        curVal=(curVal+num)%totalVal;
    }
    
    vector<int> getPos() {
        auto key=getPair(curVal,W,H);

        int x=key.first.first;
        int y=key.first.second;

        return {x,y};
    }
    
    string getDir() {
        if(curVal==0 && moved) return "South";
        auto key=getPair(curVal,W,H);

        return key.second;
    }
};

/**
 * Your Robot object will be instantiated and called as such:
 * Robot* obj = new Robot(width, height);
 * obj->step(num);
 * vector<int> param_2 = obj->getPos();
 * string param_3 = obj->getDir();
 */

// BRUTE FORCE APPROACH : O(MAX(ROWS,COLS)*STEPS)
class Robot {
private:
int x,y,cols,rows;
string dir;
unordered_map<string,pair<int,int>> dirVal;


string changeDirection(string &prevDir){
    string nextDir="";
    if(prevDir=="East"){
        nextDir="North";
    }
    else if(prevDir=="West"){
        nextDir="South";
    }
    else if(prevDir=="North"){
        nextDir="West";
    }
    else if(prevDir=="South"){
        nextDir="East";
    }
    return nextDir;
}

bool checkOutBounds(int x,int y){
    return (x>=cols || x<0 || y>=rows || y<0);
}
public:
    Robot(int width, int height) {
        cols=width;
        rows=height;
        dir="East";
        x=0;
        y=0;
        dirVal["East"]={1,0};
        dirVal["West"]={-1,0};
        dirVal["North"]={0,1};
        dirVal["South"]={0,-1};
    }
    
    void step(int num) {
        int steps=1;

        while(steps<=num){
            auto key=dirVal[dir];
            int nxtX=x+key.first;
            int nxtY=y+key.second;

            if(checkOutBounds(nxtX,nxtY)){
                dir=changeDirection(dir);
                continue;
            }
            x=nxtX;
            y=nxtY;
            steps++;
        }
    }
    
    vector<int> getPos() {
        return {x,y}; 
    }
    
    string getDir() {
        return dir;
    }
};

/**
 * Your Robot object will be instantiated and called as such:
 * Robot* obj = new Robot(width, height);
 * obj->step(num);
 * vector<int> param_2 = obj->getPos();
 * string param_3 = obj->getDir();
 */
