class Solution {
public:
    vector<vector<int>> sortMatrix(vector<vector<int>>& grid) {
        unordered_map<int,vector<int>> mp;

        for(int i=0;i<grid.size();i++){
            for(int j=0;j<grid[0].size();j++){
                int idx=i-j;
                mp[idx].push_back(grid[i][j]);
            }
        }


        for(auto &it:mp){
            if(it.first>=0){
                sort(it.second.begin(),it.second.end());
            }
            else{
                sort(it.second.begin(),it.second.end(),greater<int>());
            }
        }

        
        for(int i=0;i<grid.size();i++){
            for(int j=0;j<grid[0].size();j++){
                int idx=i-j;
                grid[i][j]=mp[idx].back();
                mp[idx].pop_back();
            }
        }


        return grid;
    }
};
