// APPROACH 2:
// SPACE REDUCED TO O(1) USING TRANSPOSE AND REVERSE METHODS
class Solution {
bool isEqual(vector<vector<int>>& mat, vector<vector<int>>& target){
    int n=mat.size();

    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            if(mat[i][j]!=target[i][j]) return false;
        }
    }
    return true;
}

void transpose(vector<vector<int>>&mat){
    int n=mat.size();


    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            if(i<=j) continue;

            int temp=mat[i][j];
            mat[i][j]=mat[j][i];
            mat[j][i]=temp;
        }
    }
}


void reverseRows(vector<vector<int>>&mat){

    for(auto &vec:mat){
        reverse(begin(vec),end(vec));
    }
}
public:
    bool findRotation(vector<vector<int>>& mat, vector<vector<int>>& target) {
        int n=mat.size();

        // at max we can have n+1 rotations
        int maxRotations=n+1;

        while(maxRotations>=0){
            if(isEqual(mat,target)) return true;

            // try to rotate
            // transpose
            transpose(mat);
            reverseRows(mat);
            maxRotations--;
        }
        return false;
    }
};


// BRUTE FORCE APPROACH
// TIME : O(N^3)
// SPACE: O(N^2)

class Solution {
bool isEqual(vector<vector<int>>& mat, vector<vector<int>>& target){
    int n=mat.size();

    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            if(mat[i][j]!=target[i][j]) return false;
        }
    }
    return true;
}
public:
    bool findRotation(vector<vector<int>>& mat, vector<vector<int>>& target) {
        int n=mat.size();

        // at max we can have n+1 rotations
        int maxRotations=n+1;

        while(maxRotations>=0){
            if(isEqual(mat,target)) return true;

            // try to rotate
            vector<vector<int>> temp(n,vector<int>(n,0));
            int curColIdx=n-1;
            for(int i=0;i<n;i++){
                for(int j=0;j<n;j++){
                    temp[j][curColIdx]=mat[i][j];
                }
                curColIdx--;
            }

            mat=temp;
            maxRotations--;
        }
        return false;
    }
};
