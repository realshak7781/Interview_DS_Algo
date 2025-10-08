class Solution {
private:
unordered_map<char,pair<int,int>> mp;
void generateCoordinates(){
    mp['U']={0,1};
    mp['D']={0,-1};
    mp['L']={-1,0};
    mp['R']={1,0};
}
public:
    int distinctPoints(string s, int k) {
        int n=s.length();
        generateCoordinates();

        set<pair<int,int>> st;
        // to store the distinct cooordinate

        vector<int> x(n),px(n);
        vector<int> y(n),py(n);

        for(int i=0;i<n;i++){
            char c=s[i];
            int xC=mp[c].first;
            int yC=mp[c].second;

            x[i]=xC;
            y[i]=yC;
        }

        // create the prefix sums px and py
        px[0]=x[0];
        py[0]=y[0];

        for(int i=1;i<n;i++){
            px[i]=x[i]+px[i-1];
            py[i]=y[i]+py[i-1];
        }


        for(int i=0;i<=(n-k);i++){
            // each index can be treated as the starting point for substring removal
            int start=i;
            int end=start+k-1;

            int dx=(px[n-1]-px[end]) + (start-1<0 ? 0: px[start-1]);
            int dy=(py[n-1]-py[end]) + (start-1<0 ? 0 : py[start-1]);

            int nx=0+dx;
            int ny=0+dy;

            st.insert({nx,ny});
        }

        return st.size();
    }
};
