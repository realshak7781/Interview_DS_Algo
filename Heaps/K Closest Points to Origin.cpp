class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
//         use max Heap to keep the biggest at top
        
        priority_queue<pair<int,pair<int,int>> > maxHeap;
        
        for(auto &it:points){
            int x=it[0];
            int y=it[1];    
            int powVal=  pow(x,2)+pow(y,2); 
            
            if(maxHeap.size()<k){
                maxHeap.push({powVal,{x,y}});
            }
            else{
                int top=maxHeap.top().first;
                
                if(powVal<top){
                    maxHeap.pop();
                    
                    maxHeap.push({powVal,{x,y}});
                }
            }
        }
        
        vector<vector<int>>res;
        
        while(!maxHeap.empty()){
            int x=maxHeap.top().second.first;
            int y=maxHeap.top().second.second;
            
            maxHeap.pop();
            res.push_back({x,y});
        }
        
        return res;
    }
};
