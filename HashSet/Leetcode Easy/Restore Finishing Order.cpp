class Solution {
public:
    vector<int> recoverOrder(vector<int>& order, vector<int>& friends) {
        unordered_map<int,int> pos;

        for(int i=0;i<order.size();i++){
            pos[order[i]]=i;
        }

        vector<pair<int,int>> arr;

        for(int i=0;i<friends.size();i++){
            arr.push_back({pos[friends[i]],friends[i]});
        }

        sort(begin(arr),end(arr));

        friends.clear();

        for(int i=0;i<arr.size();i++){
            friends.push_back(arr[i].second);
        }

        return friends;
    }
};
