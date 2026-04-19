// OPTIMIZED APPROACH
//USING MATHEMATICAL PATTERN OF SKIPS
// OPTIMIZED APPROACH
class Solution {
public:
    string decodeCiphertext(string encodedText, int rows) {
        int len=encodedText.length();
        int cols=len/rows;

        int skips=cols+1;
        int totalIterations=rows;

        int c=0;
        string originalTxt="";
        while(c<cols){

            int stringIdx=c;

            for(int it=0;it<totalIterations;it++){
                if(stringIdx>=len) break;
                originalTxt+=encodedText[stringIdx];
                stringIdx+=skips;
            }
            c++;
        }
        // remove the trailing space 
        int idx=-1;
        for(int i=originalTxt.length()-1;i>=0;i--){
            if(originalTxt[i]!=' '){
                idx=i;
                break;
            }
        }

        if(idx!=-1){
            originalTxt=originalTxt.substr(0,idx+1);
        }
        return originalTxt;
    }
};


// TIME : O(ROWS*COLS)
// SPACE : O(ROWS*COLS)
// BRUTE FORCE APPROACH : USING EXTRA SPACE TO CREATE THE CIPHER MATRIX'
class Solution {
public:
    string decodeCiphertext(string encodedText, int rows) {
        int len=encodedText.length();
        int cols=len/rows;

        vector<vector<char>> cipher(rows,vector<char>(cols,' '));
        int r=-1,c=-1;

        for(int i=0;i<len;i++){
            if(i%cols==0){
                r++;
            }
            c=(c+1)%cols;
            char cur=encodedText[i];

            cipher[r][c]=cur;
        }

        // now cipher array is created
        // get the originalText back


        string originalTxt="";
        int j=0;
        while(j<cols){
            int k=j; 
            for(int i=0;i<rows;i++){
                if(k>=cols) break;
                originalTxt+=cipher[i][k];
                k++;
            }
            j++;
        }


        // remove the trailing space 
        int idx=-1;
        for(int i=originalTxt.length()-1;i>=0;i--){
            if(originalTxt[i]!=' '){
                idx=i;
                break;
            }
        }

        if(idx!=-1){
            originalTxt=originalTxt.substr(0,idx+1);
        }
        return originalTxt;
    }
};
