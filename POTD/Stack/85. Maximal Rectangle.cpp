// Time : O(m*n)
// space: O(n) 

class Solution {
private:
vector<int> getPse(vector<int>&heights){
    int n=heights.size();

    stack<int> st;
    // push the indexes;
    vector<int> pse(n,0);
    for(int i=0;i<n;i++){
        int curHeight=heights[i];

        while(!st.empty() && heights[st.top()] >=curHeight) st.pop();

        if(st.empty()){
            pse[i]=-1;
        }
        else{
            pse[i]=st.top();
        }

        st.push(i);
    }

    return pse;
}

vector<int> getNse(vector<int>&heights){
    int n=heights.size();

    stack<int> st;
    // push the indexes;
    vector<int> nse(n,0);
    for(int i=n-1;i>=0;i--){
        int curHeight=heights[i];

        while(!st.empty() && heights[st.top()]>=curHeight) st.pop();

        if(st.empty()){
            nse[i]=n;
        }
        else{
            nse[i]=st.top();
        }

        st.push(i);
    }

    return nse;
}
int getMaxArea(vector<int>&heights){
    int n=heights.size();

    vector<int> pse=getPse(heights);
    vector<int> nse=getNse(heights);

    int maxArea=0;

    for(int i=0;i<n;i++){
        int width=nse[i]-pse[i]-1;
        int curHeight=heights[i];

        maxArea=max(maxArea,width*curHeight);
    }

    return maxArea;
}
public:
    int maximalRectangle(vector<vector<char>>& matrix) {
        int m=matrix.size();
        int n=matrix[0].size();

        vector<int> heights(n,0);

        int maxArea=0;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(matrix[i][j]=='0') {
                    heights[j]=0;
                }
                else{
                    heights[j]++;
                }
            }
            maxArea=max(maxArea,getMaxArea(heights));
        }

        return maxArea;
    }
};
