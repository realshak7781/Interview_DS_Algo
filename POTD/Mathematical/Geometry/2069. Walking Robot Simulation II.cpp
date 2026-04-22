

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
