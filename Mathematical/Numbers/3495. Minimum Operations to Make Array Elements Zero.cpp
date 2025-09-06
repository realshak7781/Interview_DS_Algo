// TIME COMPLEXITY: o(Q*15)
// AT MAX 15 OPERATIONS CAN HAPPEN INSIDE WHILE LOOP CAN BE PROVED MATHEMATICALLY
// SPACE : O(1)
using ll=long long;
class Solution {
public:
    long long minOperations(vector<vector<int>>& queries) {
        // observation number :
        // if for a no x you keep dividing with 4
        // and  and at last its floor value should be zero then after t operations
        // 0 <= (x/4^t)  <1
        // when you take log to find the value of t : you get
        // t > log4(x)

        // so min no of operations : or min value of t is
        // the smallest t greater than log4(x) is floor(log4(x))+1

        ll totalOps=0;
        for(auto &q:queries){
            ll l=q[0];
            ll r=q[1];

            ll L=1;
            ll R=4*L-1;
            ll S=1;
            ll count=0;
            while(r>=L){

                if(l<=R){
                  ll start=max(l,L);
                   ll end=min(r,R);
                   count+= (ll)S*(ll)(end-start+1);
                }
                

                S++;
                L=(long)L*4;
                R=(long)4*L-1;
            }

            if(count&1){
                totalOps+= (long long)(count+1)/2;
            }
            else{
                totalOps+=(long long)count/2;
            }
        }

       

        return totalOps;
    }
};
