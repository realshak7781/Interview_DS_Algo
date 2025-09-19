class Spreadsheet {
private:
unordered_map<string,int> spreadsheet;
public:
    Spreadsheet(int rows) {
        // nothing to do here
    }
    
    void setCell(string cell, int value) {
        spreadsheet[cell]=value;
    }
    
    void resetCell(string cell) {
        spreadsheet[cell]=0;
    }
    
    int getValue(string formula) {
        string x,y;
        bool fillY=false;
        bool sX=false;
        bool sY=false;
        for(int i=1;i<formula.length();i++){
            if(formula[i]=='+'){
                fillY=true;
                continue;
            }

            if(fillY){
                if(isalpha(formula[i])){
                    sY=true;
                }
                y+=formula[i];
            }
            else{
                 if(isalpha(formula[i])){
                    sX=true;
                }
                x+=formula[i];
            }
        }

        int xVal=0,yVal=0;

        if(sX){
            xVal=spreadsheet[x];
        }
        else{
            xVal=stoi(x);
        }

        if(sY){
            yVal=spreadsheet[y];
        }
        else{
            yVal=stoi(y);
        }

        return xVal+yVal;
    }
};

