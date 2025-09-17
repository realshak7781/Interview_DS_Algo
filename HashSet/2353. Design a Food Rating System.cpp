struct cmp{
    bool operator()(const pair<int,string>&a,const pair<int,string>&b) const{
        if(a.first!=b.first){
            return a.first>b.first;
        }

        return a.second<b.second;
    }
};

class FoodRatings {
private:
unordered_map<string, set<pair<int, string>, cmp>> getRating;
unordered_map<string,int> iR;
unordered_map<string,string> iC;
public:
    FoodRatings(vector<string>& foods, vector<string>& cuisines, vector<int>& ratings) {
        int size=foods.size();

        for(int i=0;i<size;i++){
            getRating[cuisines[i]].insert({ratings[i],foods[i]});
            iR[foods[i]]=ratings[i];
            iC[foods[i]]=cuisines[i];
        }
    }
    
    void changeRating(string food, int newRating) {
        int oldRating=iR[food];
        iR[food]=newRating;

        string cusin=iC[food];
        auto &st=getRating[cusin];

        if(st.count({oldRating,food}))st.erase({oldRating,food});

        st.insert({newRating,food});
    }
    
    string highestRated(string cuisine) {
        auto &st=getRating[cuisine];
        auto res=*st.begin();

        string item=res.second;

        return item;
    }
};

