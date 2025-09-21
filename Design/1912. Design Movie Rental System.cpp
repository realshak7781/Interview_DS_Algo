class MovieRentingSystem {
private:
    unordered_map<int, set<pair<int, int>>> mP;
    unordered_map<string, int> priceMp;
    set<pair<int, pair<int, int>>> rented;

public:
    MovieRentingSystem(int n, vector<vector<int>>& entries) {
        for (auto& e : entries) {
            int shop = e[0];
            int movie = e[1];
            int price = e[2];

            mP[movie].insert({price, shop});
            string key = "_" + to_string(movie) + "_" + to_string(shop) + "_";
            priceMp[key] = price;
        }
    }

    vector<int> search(int movie) {
        vector<int> res;

        auto& st = mP[movie];

        int count = 0;
        int max_count = 5;

        for (auto it = st.begin(); it != st.end() && count < max_count; ++it) {
            res.push_back(it->second);
            count++;
        }

        return res;
    }

    void rent(int shop, int movie) {
        string key = "_" + to_string(movie) + "_" + to_string(shop) + "_";
        int price = priceMp[key];

        mP[movie].erase({price, shop});
        rented.insert({price, {shop, movie}});

        // when you rent: remove from mP and add to rented
    }

    void drop(int shop, int movie) {
        // when you drop , add back to mP and remove from rented
        // just the inverse of rent
        string key = "_" + to_string(movie) + "_" + to_string(shop) + "_";
        int price = priceMp[key];

        mP[movie].insert({price, shop});
        rented.erase({price, {shop, movie}});
    }

    vector<vector<int>> report() {
        vector<vector<int>> res;
        // {shop,movie} sorted by price

        int count=0;
        int max_count=5;
        for (auto it = rented.begin(); it != rented.end() && count < max_count; ++it) {
            int shop=it->second.first;
            int movie=it->second.second;

            res.push_back({shop,movie});
            count++;
        }

        return res;
    }
};
