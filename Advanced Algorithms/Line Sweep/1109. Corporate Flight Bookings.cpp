
// Optimal APProach : Using Difference Array technique
class Solution {
public:
    vector<int> corpFlightBookings(vector<vector<int>>& bookings, int n) {
        vector<int> res(n,0);

        for(auto &b:bookings){
            int l=b[0]-1;
            int r=b[1];
            int seats=b[2];

            res[l]+=seats;
            if(r<n) res[r]-=seats;
        }

        for(int i=1;i<n;i++){
            res[i]+=res[i-1];
        }

        return res;
    }
};

// Brute force :
// time : O(B*(O(r-l+1))
class Solution {
public:
    vector<int> corpFlightBookings(vector<vector<int>>& bookings, int n) {
        vector<int> res(n,0);

        for(auto &b:bookings){
            int l=b[0]-1;
            int r=b[1]-1;
            int seats=b[2];
            for(int i=l;i<=r;i++){
                res[i]+=seats;
            }
        }

        return res;
    }
};
