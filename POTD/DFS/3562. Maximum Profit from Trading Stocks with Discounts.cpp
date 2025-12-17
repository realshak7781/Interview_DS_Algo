class Solution {
private:
void dfs(int u,int n, vector<int>& present, vector<int>& future,int budget,unordered_map<int,vector<int>>&adjList,vector<vector<vector<int>>> &statesProfit){

    vector<pair<vector<int>,vector<int>>> childrenStatesProfit;

    for(int v:adjList[u]){
        dfs(v,n,present,future,budget,adjList,statesProfit);
        childrenStatesProfit.push_back({statesProfit[v][0], statesProfit[v][1]});
    }

    for(int parentBought=0;parentBought<=1;parentBought++){
        int price= (parentBought == 1) ? present[u] / 2 : present[u];
        int profit=future[u]-price;

        vector<int> bestProfitAtU(budget + 1, 0);
        vector<int> childrenProfitIfUNotBought(budget + 1, 0);

         for (const auto& child : childrenStatesProfit) { //from all child
                vector<int> temp(budget + 1, 0);

                for (int used = 0; used <= budget; ++used) { 
                    for (int take = 0; used + take <= budget; ++take) { 
                        temp[used + take] = max(temp[used + take], childrenProfitIfUNotBought[used] + child.first[take]);
                    }
                }
                childrenProfitIfUNotBought = move(temp);
            }

             for (int b = 0; b <= budget; ++b) {
                bestProfitAtU[b] = max(bestProfitAtU[b], childrenProfitIfUNotBought[b]);
            }


            if(price<=budget){
                 vector<int> childrenProfitIfUBought(budget + 1, 0);

                for (const auto& child : childrenStatesProfit) { //from all child
                    vector<int> temp(budget + 1, 0);

                    for (int used = 0; used <= budget; ++used) {
                        for (int take = 0; used + take <= budget; ++take) {
                            temp[used + take] = max(temp[used + take], childrenProfitIfUBought[used] + child.second[take]);
                        }
                    }
                    childrenProfitIfUBought = move(temp);
                }

                for (int b = price; b <= budget; ++b) {
                    bestProfitAtU[b] = max(bestProfitAtU[b], childrenProfitIfUBought[b - price] + profit);
                }
            }

         statesProfit[u][parentBought] = move(bestProfitAtU);
    }
}
public:
    int maxProfit(int n, vector<int>& present, vector<int>& future, vector<vector<int>>& hierarchy, int budget) {
        unordered_map<int,vector<int>> adjList;

        for(auto &it:hierarchy){
            int u=it[0]-1;
            int v=it[1]-1;

            adjList[u].push_back(v);
        }

        vector<vector<vector<int>>> statesProfit(n,vector<vector<int>>(2,vector<int>(budget + 1, 0)));

        dfs(0,n,present,future,budget,adjList,statesProfit);

        int res=0;
        for(int b=0;b<=budget;b++){
            res=max(res,statesProfit[0][0][b]);
        }

        return res;
    }
};
